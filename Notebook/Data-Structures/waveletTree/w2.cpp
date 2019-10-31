#include <bits/stdc++.h>
using namespace std;

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

			for (auto it = beg; it != end; it++) {
				mapLeft.push_back(mapLeft.back() + 1);
			}
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

	/** K-th smallest element on range[l..r] */
	int kthSmallest(int k, int l, int r) {
		if (l > r) return -1; // out of bounds
		if (lo == hi) return lo; // leaf node

		int inLeft = mapLeft[r] - mapLeft[l-1];
		if (k <= inLeft) return L->kthSmallest(k, mapLeft[l-1]+1, mapLeft[r]);
		else return R->kthSmallest(k-inLeft, mapRight[l-1]+1, mapRight[r]);
	}

	/** Swap elements a[i] and a[i+1] */
	void swapContiguous(int i) {
		if (lo == hi) return; // leaf node, no need to swap
		int mi = (lo + hi) / 2;

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

	~waveletTree() {
		if (L) delete L;
		if (R) delete R;
	}
};
 
const int MAXN = 1e5 + 5;

int a[MAXN];
map<int, int> mp, inv;

int compress(int n) {
	set<int> all;
	for (int i = 1; i <= n; i++) all.insert(a[i]);

	int cnt = 0;
	for (int i : all) {
		mp[i] = ++cnt;
		inv[cnt] = i;
	}

	for (int i = 1; i <= n; i++) a[i] = mp[a[i]];

	return cnt;
}

int main() {
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);

	int N = compress(n);
	waveletTree T(a+1, a+n+1, 1, N);

	while(q--) {
		char op; scanf(" %c", &op);
		if (op == 'Q') {
			int l, r, k; scanf("%d%d%d", &l, &r, &k);
			int ans = T.kthSmallest(k, l, r);
			printf("%d\n", inv[ans]);
		} else {
			int i; scanf("%d", &i);
			T.swapContiguous(i);
		}
	}
 
	return 0;
}