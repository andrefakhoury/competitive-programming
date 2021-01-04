#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e3 + 5, INF = 0x3f3f3f3f;

#define y1 asiudhasidhsad
#define y2 asodsaos
#define x1 ais0222
#define x2 asd0so22929

int a[MAXN][MAXN];

struct Rect {
	int x1, y1, x2, y2;
	void read() {
		cin >> x1 >> y1 >> x2 >> y2;
		--x1; --y1; --x2; --y2;
	}
};

int sz[MAXN * MAXN];
int par[MAXN * MAXN];

int n, m;
int get(int i, int j) {
	return i * m + j;
}

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

int ans;

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (sz[u] > sz[v]) swap(u, v);
//	cerr << "merging " << u/m << "," << u%m << " and " << v/m << "," << v%m << "\n";
	par[u] = v;
	sz[v] += sz[u];
	ans--;
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void merge_neigh(int i, int j) {
	for (int k = 0; k < 4; k++) {
		int I = i + dx[k];
		int J = j + dy[k];
		if (I >= 0 && J >= 0 && I < n && J < m && a[I][J] == -1) {
			merge(get(I, J), get(i, j));
		}
	}
}

int qtBranco;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int q; cin >> n >> m >> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			par[get(i, j)] = get(i, j);
			sz[get(i, j)] = 1;
		}

	qtBranco = n * m;
	ans = n * m;

	vector<Rect> queries(q);

	mset(a, -1);

	for (int i = 0; i < q; i++) {
		queries[i].read();
		for (int x = queries[i].x1; x <= queries[i].x2; x++) {
			for (int y = queries[i].y1; y <= queries[i].y2; y++) {
				if (a[x][y] == -1) {
					a[x][y] = i;
					qtBranco--;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == -1) merge_neigh(i, j);


	vector<int> anss(q);
	for (int i = q-1; i >= 0; i--) {
		anss[i] = ans - (n * m - qtBranco);

		for (int x = queries[i].x1; x <= queries[i].x2; x++) {
			for (int y = queries[i].y1; y <= queries[i].y2; y++) {
				if (a[x][y] == i) {
					a[x][y] = -1;
					qtBranco++;
					merge_neigh(x, y);
				}
			}
		}
	}

	for (int i = 0; i < q; i++)
		cout << anss[i] << "\n";
}