#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> edges[MAXN];
int sz[MAXN];

int dfs_size(int u, int p) {
	sz[u] = 1;
	for (int v : edges[u])
		if (v != p) sz[u] += dfs_size(v, u);
	return sz[u];
}

int dfs_cent(int u, int p, int qtt) {
	for (int v : edges[u])
		if (v != p && sz[v] > qtt/2) return dfs_cent(v, u, qtt);
	return u;
}

inline int centroid(int u) {
	return dfs_cent(u, u, dfs_size(u, u));
}

int main() {
	
}