#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) {cout.flush(); fflush(stdout); fprintf(stderr, args);}
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
	x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

/** Wavelet. Tree. O(logn). Thats it. */
struct WaveletTree {
	struct Node {
		int lo, hi, mi;
		int L, R;
		vector<int> mapLeft, mapRight;
	};

	vector<Node> nodes;

	/** Builds tree nodes */
	void build(int p, int* beg, int* end, int lo, int hi) {
		nodes[p].lo = lo;
		nodes[p].hi = hi;
		nodes[p].mi = (lo + hi) / 2;
		nodes[p].L = nodes[p].R = -1;

		nodes[p].mapLeft.reserve(end - beg + 1);
		nodes[p].mapLeft.eb(0);

		if (lo == hi) { // leaf
			for (auto it = beg; it != end; it++)
				nodes[p].mapLeft.eb(nodes[p].mapLeft.back() + 1);
		} else {
			nodes[p].mapRight.reserve(end - beg + 1);
			nodes[p].mapRight.eb(0);

			auto f = [&](int x) { return x <= nodes[p].mi; };
			for (auto it = beg; it != end; it++) {
				nodes[p].mapLeft.eb(nodes[p].mapLeft.back() + f(*it));
				nodes[p].mapRight.eb(nodes[p].mapRight.back() + !f(*it));
			}

			auto pivot = stable_partition(beg, end, f);
			nodes[p].L = nodes.size();
			nodes.eb();
			nodes[p].R = nodes.size();
			nodes.eb();
			build(nodes[p].L, beg, pivot, lo, nodes[p].mi);
			build(nodes[p].R, pivot, end, nodes[p].mi + 1, hi);
		}
	}

	/** Initialize tree */
	inline void init(int* beg, int* end, int lo, int hi) {
		nodes.reserve(end - beg + 1);
		nodes.eb();
		build(0, beg, end, lo, hi);
	}

	/** Frequency of k on range [1..i] */
	int rank(int k, int i, int p = 0) {
		if (i <= 0) return 0;
		if (nodes[p].lo == nodes[p].hi) {
			if (k == nodes[p].lo) return i;
			return 0;
		} else {
			if (k <= nodes[p].mi) return rank(k, nodes[p].mapLeft[i], nodes[p].L);
			else return rank(k, nodes[p].mapRight[i], nodes[p].R);
		}
	}

	/** Frequency of k in range [i..j] */
	int rankRange(int k, int l, int r) {
		return rank(k, r) - rank(k, l-1);
	}

	/** K-th smallest element on range[l..r] */
	int kthSmallest(int k, int l, int r, int p = 0) {
		if (l > r) return -1; // out of bounds
		if (nodes[p].lo == nodes[p].hi) return nodes[p].lo; // leaf node

		int inLeft = nodes[p].mapLeft[r] - nodes[p].mapLeft[l-1];
		if (k <= inLeft) return kthSmallest(k, nodes[p].mapLeft[l-1]+1, nodes[p].mapLeft[r], nodes[p].L);
		else return kthSmallest(k-inLeft, nodes[p].mapRight[l-1]+1, nodes[p].mapRight[r], nodes[p].R);
	}

	/** Qtt of elements between [x..y] in array[l..r] */
	int rangeCount(int x, int y, int l, int r, int p = 0) {
		if (l > r) return 0;
		if (nodes[p].lo > y || nodes[p].hi < x) return 0; // out of bounds
		if (nodes[p].lo >= x && nodes[p].hi <= y) return r - l + 1; // total fit
		
		return rangeCount(x, nodes[p].mi, nodes[p].mapLeft[l-1]+1, nodes[p].mapLeft[r], nodes[p].L) + 
			rangeCount(nodes[p].mi+1, y, nodes[p].mapRight[l-1]+1, nodes[p].mapRight[r], nodes[p].R);
	}

	/** Swap elements a[i] and a[i+1] */
	void swapContiguous(int i, int p = 0) {
		if (nodes[p].lo == nodes[p].hi) return; // leaf node, no need to swap

		bool iLeft = nodes[p].mapLeft[i] == nodes[p].mapLeft[i-1] + 1; // if a[i] <= mi
		bool i1Left = nodes[p].mapLeft[i+1] == nodes[p].mapLeft[i] + 1; // if a[i+1] <= mi

		if (iLeft && !i1Left) {
			nodes[p].mapLeft[i]--;
			nodes[p].mapRight[i]++;
		} else if (iLeft && i1Left) {
			swapContiguous(nodes[p].mapLeft[i], nodes[p].L);
		} else if (!iLeft && i1Left) {
			nodes[p].mapLeft[i]++;
			nodes[p].mapRight[i]--;
		} else {
			swapContiguous(nodes[p].mapRight[i], nodes[p].R);
		}
	}

	/** Push element k to end of array */
	void push_back(int k, int p = 0) {
		if (nodes[p].lo == nodes[p].hi) {
			nodes[p].mapLeft.push_back(nodes[p].mapLeft.back() + 1);
		} else {
			if (k <= nodes[p].mi) {
				nodes[p].mapLeft.push_back(nodes[p].mapLeft.back() + 1);
				nodes[p].mapRight.push_back(nodes[p].mapRight.back());
				push_back(k, nodes[p].L);
			} else {
				nodes[p].mapRight.push_back(nodes[p].mapRight.back() + 1);
				nodes[p].mapLeft.push_back(nodes[p].mapLeft.back());
				push_back(k, nodes[p].R);
			}
		}
	}

	/** Pop element k from the end of array */
	void pop_back(int k, int p = 0) {
		if (nodes[p].lo == nodes[p].hi) {
			nodes[p].mapLeft.pop_back();
		} else {
			nodes[p].mapLeft.pop_back();
			nodes[p].mapRight.pop_back();
			if (k <= nodes[p].mi) pop_back(k, nodes[p].L);
			else pop_back(k, nodes[p].R);
		}
	}
} T;

int a[MAXN], n, q;
int original[MAXN];
 
inline int compress() {
	vector<int> all;
	for (int i = 1; i <= n; i++) all.eb(a[i]);

	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());

	auto get = [&](int x) {
		return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
	};

	for (int i = 1; i <= n; i++) {
		int u = get(a[i]);
		original[u] = a[i];
		a[i] = u;
	}

	return all.size();
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);
	int N = compress();
	
	T.init(a+1, a+n+1, 1, N);

	while(q--) {
		int l, r, k; scanf("%d%d%d", &l, &r, &k);
		int ans = T.kthSmallest(k, l, r);
		printf("%d\n", original[ans]);
	}

	return 0;
}