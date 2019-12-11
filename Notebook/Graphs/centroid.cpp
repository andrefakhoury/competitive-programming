#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

// vector<int> edges[MAXN];
// int sz[MAXN];

// int dfs(int u, int p = -1) {
// 	for (int v : edges[u]) {
// 		if (v != p) sz[u] += dfs(v, u);
// 	}

// 	return sz[u] + 1;
// }

// int centroid(int u, int p = -1) {
// 	for (int v : edges[u]) {
// 		if (v != p && sz[v] > n/2)
// 			return centroid(v, u);
// 	}
// 	return u;	
// }

struct CentroidDecomposition {
	vector<set<int>> tree;
	vector<int> par, sz;

	CentroidDecomposition() {
		int n = tree.size();
		par.resize(n);
	}
};

int main() {

}