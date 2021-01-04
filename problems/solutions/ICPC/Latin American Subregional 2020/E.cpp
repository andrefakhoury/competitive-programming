#include <bits/stdc++.h>

#define deb(x) (cout << #x << ": " << x << endl)
#define pb push_back
#define fi first
#define se second
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e5 + 7;

vector<int> e[N];
int pai[N][20], vis[N][2];
int age[N], L[N], R[N], ans[N];
vector<int> tim[N];
vector<int> que[N][2];

int tt;

void dfs(int u) {

	vis[u][0] = ++tt;
	// monta bin lifting
	tim[tt].pb(u);
	for(int i = 1; i < 20; ++i) {
		pai[u][i] = pai[pai[u][i-1]][i-1];
	}
	for(int v : e[u]) {
		if(v == pai[u][0]) continue;
		dfs(v);
	}

	vis[u][1] = tt;
}


// acha cara mais acima com valor maior ou igual a x
int calc(int u, int x) {
	// deb(x);
	for(int i = 19; i >= 0; --i) {
		int v = pai[u][i];
		// deb(v);
		if(age[v] <= x) u = v;
	}

	return u;
}

struct segtree {
	vector<int> seg;
	int n;
	segtree(){}
	segtree(int n) {
		seg.assign(n + n, 0);
		this->n = n;
	}

	int query(int p) {
		int ans = 0;
		for(p += n; p > 0; p >>= 1) {
			ans += seg[p];
		}
		return ans;
	}
	void update(int l, int r, int val) {
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l&1) seg[l] += val, l++;
			if(r&1) --r, seg[r] += val;
		}
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;

	vector<int> vec;
	for(int i = 1; i <= n; ++i) {
		cin >> age[i] >> pai[i][0];
		e[pai[i][0]].pb(i);
		vec.pb(age[i]);
	}

	dfs(1);

	for(int i = 1; i <= m; ++i) {
		int anf;
		cin >> anf >> L[i] >> R[i];

		vec.pb(L[i]);
		vec.pb(R[i]);
		// recalcula o anfitriao
		anf = calc(anf, R[i]);
		// cout << anf << ' ';
		que[vis[anf][0]][0].eb(i);
		que[vis[anf][1]][1].eb(i);
	}
	// cout << endl;

	// comprime
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	// comprime
	for(int i = 1; i <= n; ++i) {
		age[i] = lower_bound(vec.begin(), vec.end(), age[i]) - vec.begin();
	}
	for(int i = 1; i <= m; ++i) {
		L[i] = lower_bound(vec.begin(), vec.end(), L[i]) - vec.begin();
		R[i] = lower_bound(vec.begin(), vec.end(), R[i]) - vec.begin();
	}


	segtree seg(vec.size());
	for(int i = 1; i <= tt; ++i) {
		// primeiro adiciona os caras tudo
		for(int id : que[i][0]) {
			seg.update(L[id], R[id]+1, 1);
		}

		for(int x : tim[i]) {
			ans[x] = seg.query(age[x]);
		}

		for(int id : que[i][1]) {
			seg.update(L[id], R[id]+1, -1);
		}
	}

	for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
	cout << endl;
}