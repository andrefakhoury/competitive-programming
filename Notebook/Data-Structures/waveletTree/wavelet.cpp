#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

/** Wavelet Tree data structure. 1-based pls :) */
struct waveletTree {
	int lo, hi; // minimum and maximum element on array
	waveletTree *L, *R; // children
	vector<int> mapLeft, mapRight; // indexes to map left and right children

	/** Builds the wavelet tree, with elements on range [lo..hi] */
	waveletTree(int *beg, int *end, int lo, int hi) { // O(nlogA). obs: the input array is 0 based
		L = R = NULL;

		this->lo = lo;
		this->hi = hi;

		if (beg >= end) return; // no elements to insert

		if (lo == hi) { // leaf node
			mapLeft.reserve(end - beg + 1);
			mapLeft.push_back(0);

			for (auto it = beg; it != end; it++)
				mapLeft.push_back(mapLeft.back() + 1);
		} else {
			int mi = (lo + hi) / 2;
			auto f = [mi](int x) { // lambda function to help index
				return x <= mi;
			};

			mapLeft.reserve(end - beg + 1);
			mapRight.reserve(end - beg + 1);

			mapLeft.push_back(0);
			mapRight.push_back(0);

			for (auto it = beg; it != end; it++) {
				mapLeft.push_back(mapLeft.back() + f(*it));
				mapRight.push_back(mapRight.back() + !f(*it));
			}

			auto pivot = stable_partition(beg, end, f); // split the vector
			L = new waveletTree(beg, pivot, lo, mi);
			R = new waveletTree(pivot, end, mi + 1, hi);
		}
	}

	/** Frequency of k on range [1..i] */
	int rank(int k, int i) {
		if (i <= 0) return 0; // out of bounds

		if (lo == hi) { // leaf node - just one value available :)
			if (k == lo) return i;
			else return 0; // I think this isn't necessary, but just in case
		} else { // keep searching
			int mi = (lo + hi) / 2;
			if (k <= mi) return L->rank(k, mapLeft[i]);
			else return R->rank(k, mapRight[i]);
		}
	}

	/** Frequency of k in range [i..j] */
	int rank(int k, int i, int j) {
		return rank(k, j) - rank(k, i - 1); // similar to prefix sum
	}

	/** K-th smallest element on range[l..r] */
	int kthSmallest(int k, int l, int r) {
		if (l > r) return -1; // out of bounds
		if (lo == hi) return lo; // leaf node

		int inLeft = mapLeft[r] - mapLeft[l-1];
		if (k <= inLeft) return L->kthSmallest(k, mapLeft[l-1]+1, mapLeft[r]);
		else return R->kthSmallest(k-inLeft, mapRight[l-1]+1, mapRight[r]);
	}

	/** Qtt of elements between [x..y] in array[l..r] */
	int rangeCount(int x, int y, int l, int r) {
		if (l > r) return 0;
		if (lo > y || hi < x) return 0; // out of bounds
		if (lo >= x && hi <= y) return r - l + 1; // total fit
		
		int mi = (lo + hi) / 2;
		return L->rangeCount(x, mi, mapLeft[l-1]+1, mapLeft[r]) +  // same idea of segtree
			   R->rangeCount(mi+1, y, mapRight[l-1]+1, mapRight[r]);
	}

	/** Find minimum X such that freq[x] on interval l..r is strictly greater thank k */
	int findFreqGreater(int k, int l, int r) {
		if (r - l + 1 <= k) return -1;
		if (lo == hi) return lo;

		int cur = L->findFreqGreater(k, mapLeft[l-1]+1, mapLeft[r]);
		if (cur != -1) return cur;

		return R->findFreqGreater(k, mapRight[l-1]+1, mapRight[r]); 
	}

	/** Swap elements a[i] and a[i+1] */
	void swapContiguous(int i) {
		if (lo == hi) return; // leaf node, no need to swap

		bool iLeft = mapLeft[i] == mapLeft[i-1] + 1; // if a[i] <= mi
		bool i1Left = mapLeft[i+1] == mapLeft[i] + 1; // if a[i+1] <= mi

		if (iLeft && !i1Left) {
			mapLeft[i]--;
			mapRight[i]++;
		} else if (iLeft && i1Left) {
			L->swapContiguous(mapLeft[i]);
		} else if (!iLeft && i1Left) {
			mapLeft[i]++;
			mapRight[i]--;
		} else {
			R->swapContiguous(mapRight[i]);
		}
	}

	/** Push element k to end of array */
	void push_back(int k) {
		if (lo == hi) {
			mapLeft.push_back(mapLeft.back() + 1);
		} else {
			int mi = (lo + hi) / 2;
			if (k <= mi) {
				mapLeft.push_back(mapLeft.back() + 1);
				mapRight.push_back(mapRight.back());
				L->push_back(k);
			} else {
				mapRight.push_back(mapRight.back() + 1);
				mapLeft.push_back(mapLeft.back());
				R->push_back(k);
			}
		}
	}

	/** Pop element k from the end of array */
	void pop_back(int k) {
		if (lo == hi) {
			mapLeft.pop_back();
		} else {
			int mi = (lo + hi) / 2;
			mapLeft.pop_back();
			mapRight.pop_back();
			if (k <= mi) L->pop_back(k);
			else R->pop_back(k);
		}
	}

	~waveletTree() {
		if (L) delete L;
		if (R) delete R;
	}
};

int a[MAXN], b[MAXN], n, q;
map<int, int> original, mapTo;
map<int, vector<int> > ind;
 
int compress() {
	set<int> all;
	for (int i = 1; i <= n; i++) all.insert(a[i]);
 
	int cur = 0;
	for (int i : all) {
		mapTo[i] = ++cur;
		original[cur] = i;
	}
 
	for (int i = 1; i <= n; i++) a[i] = mapTo[a[i]];
 
	return cur;
}
 
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
		b[i] = a[i];
		ind[a[i]].push_back(i - 1);
	}
 
	int N = compress();
	waveletTree T(a+1, a+n+1, 1, N);
 
	while(q--) {
		int op; scanf("%d", &op);
		if (op == 0) {
			int k, i, l; scanf("%d%d%d", &i, &l, &k);
 
			int d = T.kthSmallest(k, 1, i + 1);
			d = original[d];
 
			int ans;
			if ((int)ind[d].size() < l) ans = -1;
			else ans = ind[d][l-1];
 
			printf("%d\n", ans);
		} else {
			int i; scanf("%d", &i);
			T.swapContiguous(++i);
 
			// agora, precisa trocar os valores de ind[b[i]] e ind[b[i+1]] tambem
			// basta acha-los e somar/subtrair 1
			auto it = lower_bound(ind[b[i]].begin(), ind[b[i]].end(), i-1) - ind[b[i]].begin();
			ind[b[i]][it]++;
 
			it = lower_bound(ind[b[i+1]].begin(), ind[b[i+1]].end(), i) - ind[b[i+1]].begin();
			ind[b[i+1]][it]--;
 
			// swap no array original tambem
			swap(b[i], b[i+1]);
		}
 
	}
 
	return 0;
}