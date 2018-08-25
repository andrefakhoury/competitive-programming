#include <bits/stdc++.h>
using namespace std;

#define mset(x, y) memset((x), (y), sizeof(x))
#define pb push_back
#define mp make_pair
#define MAXN 100005

typedef pair<int, int> pii;
typedef long long ll;

//dfs
vector<int> edges[MAXN];
bool vis[MAXN];
void dfs(int u) {
	int v;
	vis[u] = true;
	for (int i = 0; i < (int)edges[u].size(); i++) {
		v = edges[u][i];
		if (!vis[v]) dfs(v);
	}
}

//dfs retornando numero de nos
vector<int> edges[MAXN];
bool vis[MAXN];
int dfs(int u) {
	int v, h = 1;
	vis[u] = true;
	for (int i = 0; i < (int)edges[u].size(); i++) {
		v = edges[u][i];
		if (!vis[v]) h += 1+dfs(v);
	}
	return h;
}

//dfs retornando altura maxima
vector<int> edges[MAXN];
bool vis[MAXN];
int dfs(int u) {
	int v, h = 1;
	vis[u] = true;
	for (int i = 0; i < (int)edges[u].size(); i++) {
		v = edges[u][i];
		if (!vis[v]) h = max(dfs(v), h);
	}
	return 1+h;
}

//dfs ignorando um vertice
vector<int> edges[MAXN];
bool vis[MAXN];
void dfs(int u, int ign) {
	if (u == ign) return;
	int v;
	vis[u] = true;
	for (int i = 0; i < (int)edges[u].size(); i++) {
		v = edges[u][i];
		if (!vis[v]) dfs(v);
	}
}

//bfs
vector<int> edges[MAXN];
int dist[MAXN];
void bfs(int s) {
	mset(dist, -1);
	dist[s] = 0;
	queue<int> q;
	q.push(s);

	while(q.size()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < edges[u].size(); i++) {
			int v = edges[u][i];
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

//dijkstra
vector<pii> edges[MAXN];
int dist[MAXN];
void bfs(int s) {
	mset(dist, -1);
	dist[s] = 0;
	priority_queue<pii> pq;
	pq.push(mp(0, s));

	while(pq.size()) {
		int u = pq.top().second;

		pq.pop();
		for (int i = 0; i < edges[u].size(); i++) {
			int v = edges[u][i].first;
			int w = edges[u][i].second;
			if (dist[v] == -1 || dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(mp(dist[v], v));
			}
		}
	}
}

//segtree
int v[MAXN], st[4*MAXN];
#define LEFT(x) 2*(x)
#define RIGHT(x) 2*(x)+1

void build(int p, int l, int r) {
	if (l == r) st[p] = v[l]; //folha
	else {
		int mid = (l+r)/2;
		build(LEFT(p), l, mid);
		build(RIGHT(p), mid+1, r);
		st[p] = st[LEFT(p)] + st[RIGHT[p]];
	}
}

void update(int p, int l, int r, int i, int x) {
	if (l == r) st[p] = v[l] = x;
	else {
		int mid = (l+r)/2;
		if (l <= i && i <= mid) update(LEFT(p), l, mid, i, x);
		else upaate(RIGHT(p), mid+1, r, i, x);
		st[p] = st[LEFT(p)] + st[RIGHT(p)];
	}
}

ll query(int p, int l, int r, int a, int b) {
	if (a < l || b > r) return 0;
	if (a >= l && b <= r) return st[p];
	int mid = (l+r)/2;
	return query(LEFT(p), l, mid, a, b) + query(RIGHT(p), mid+1, r, a, b);
}

//segtree com lazy
void prop(int r, int i, int j) {
	if (!lazy[r]) return;
	st[r] += lazy[r]*(j-i+1);
	if (i != j) {
		lazy[LEFT(r)] += lazy[r];
		lazy[RIGHT(r)] += lazy[r];
	}
	lazy[r] = 0;
}

void update(int p, int l, int r, int x) {
	prop(p, l, r);
	if (r < a || l > b) return;

	if (l >= a && r <= b) {
		st[p] = x*(r-l+1);
		if (l != r) {
			lazy[LEFT(p)] += x;
			lazy[RIGHT(p)] += x;
		}
	} else {
		int mid = (l+r)/2;
		update(LEFT(p), l, mid, x);
		update(RIGHT(p), mid+1, r, x);
		st[p] = st[LEFT(p)] + st[RIGHT(p)];
	}
}

int query(int p, int l, int r) {
	prop(p, l, r);
	if (r < a || l > b) return 0;

	if (l >= a && r <= b) return st[p];

	int mid = (l+r)/2;
	return query(LEFT(p), l, mid) + query(RIGHT(p), mid+1, r);
}

//kruskal
int Init() {
	for (int i = 1; i <= n; i++) dad[i] = i;
}

int Find(int x) {
	if (x == dad[x]) return x;
	return dad[x] = find(dad[x]);
}

void Union(int x, int y) {
	int p = Find(x);
	int q = Find(y);
	if (p != q) dad[p] = q;
}

int kruskal() { //ordenar o vetor antes
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		int w = edges[i].first;
		if (Find(u) != Find(v)) {
			ans += w;
			Union(u, v);
		}
	}
	return ans;
}

//floyd-warshall
int dist[MAXN][MAXN];
void floyd_warshall() {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dist[i][j] = inf;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[j][k]);
}

//LIS
int v[MAXN], dp[MAXN];
int lisIT() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++)
			if (v[j] < v[i]) dp[i] = max(dp[i], dp[j]+1);
		ans = max(ans, dp[i]);
	}
	return ans;
}

int lisST() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1 + query(1, v[i]-1);
		update(v[i], dp[i]);
		ans = max(ans, dp[i]);
	}
	return ans;
}

void compressaoCoords() {
	//coloca tudo os elementos num vector<int> v;
	//e dps coloca os elementos comprimidos num int a[MAXN]

	//pra limpar tudo
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	for (int i = 1; i <= n; i++) a[i] = lower_bound(v.begin(), v.end(), a[i]);
}

int LCS() {
	map<int, int> idx;
	int a[MAXN], b[MAXN];

	for (int i = 1; i <= n; i++) scanf("%d", a+i);
	for (int i = 1; i <= n; i++) scanf("%d", b+i);

	for (int i = 1; i <= n; i++) idx[a[i]] = i;

	for (int i = 1; i <= n; i++) {
		if (idx.count(b[i])) {
			dp[i] = 1 + query(1, 1, n, 1, idx[b[i]] - 1);
			update(1, 1, n, idx[b[i]], dp[i]);
		} else dp[i] = 0;
	}
}

int kadane() {
	//maior soma ate o elemento
	ll ans = 0;

	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i-1] + a[i], a[i]);
		ans = max(ans, dp[i]);
	}
}