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

	int solveG(int k, int l, int r) {
		if (r - l + 1 < k) return 0;
		if (lo == hi) return 1;

		return L->solveG(k, mapLeft[l-1]+1, mapLeft[r]) + R->solveG(k, mapRight[l-1]+1, mapRight[r]);
	}

	~waveletTree() {
		if (L) delete L;
		if (R) delete R;
	}
};

const int MAXN = 1e5 + 5;

vector<int> edges[MAXN];
int euler[MAXN], t_in[MAXN], t_out[MAXN], color[MAXN], curT;

void dfs(int u) {
	t_in[u] = ++curT;
	euler[curT] = color[u];

	for (int v : edges[u]) if (!t_in[v]) dfs(v);
	t_out[u] = curT;
}
 
int main() {
	int n, m, M = -1; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", color+i);
		M = max(M, color[i]);
	}

	for (int i = 2; i <= n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs(1);

	waveletTree T(euler+1, euler+curT+1, 1, M);
	while(m--) {
		int v, k; scanf("%d%d", &v, &k);
		printf("%d\n", T.solveG(k, t_in[v], t_out[v]));
	}
 
	return 0;
}