#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e3 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p[MAXN], c[MAXN], a[MAXN];
vector<int> edges[MAXN];

vector<vector<int> > dfs(int u) {
	vector<vector<int> > ret;

	if (edges[u].size() == 0) {
		ret.pb(vector<int>(1));
		ret[0][0] = u;
		return ret;
	}

	for (int v : edges[u]) {
		vector<vector<int> > cur = dfs(v);
		for (int i = 0; i < (int)cur.size(); i++) {
			if (i >= (int)ret.size()) ret.pb(vector<int>());
			for (int j : cur[i]) ret[i].pb(j);
		}
	}

	ll cur = 0;

	bool ok = false;
	for (int i = 0; i < (int)ret.size(); i++) {
		if (cur + (int)ret[i].size() > c[u]) {
			// cout << "colocou na frente e separou\n";
			ok = true;
			// coloca na frente e separa
			vector<int> aux = {u};
			ret.insert(ret.begin() + i + 1, aux);

			int qtt = ret[i].size() - (c[u] - cur);
			ret.insert(ret.begin() + i + 2, vector<int>());

			for (int j = ret[i].size() - qtt; j < (int)ret[i].size(); j++)
				ret[i+2].pb(ret[i][j]);
			while(qtt--) ret[i].pop_back();

			break;
		} else if (cur + (int)ret[i].size() == c[u]) {
			// cout << "colocou na frente\n";

			vector<int> aux = {u};
			ret.insert(ret.begin() + i +1, aux);
			ok = true;
			break;
		} else cur += ret[i].size();
	}

	if (!ok) {
		cout << "NO\n";
		exit(0);
	}

	// cout << "results on\n";
	// for (auto x : ret) {
	// 	cout << x.size() << ": ";
	// 	for (auto y : x) cout << y << ' ';
	// 	cout << "\n";
	// }

	return ret;
}

int t_in[MAXN], t_out[MAXN], curT;
vector<int> euler;

void _dfs(int u) {
	t_in[u] = curT++;
	euler.pb(u);

	for (int v : edges[u]) {
		_dfs(v);
	}

	t_out[u] = curT;
}

bool check(int root) {
	_dfs(root);
	for (int i = 0; i < (int)euler.size(); i++) {
		int qtt = 0;
		for (int j = i; t_out[euler[i]] > j; j++) {
			qtt += a[euler[j]] < a[euler[i]];
		}
		if (qtt != c[euler[i]]) return 0;
	}
	return 1;

}

int main() {
	int n; scanf("%d", &n);

	int root = -1;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> c[i];
		if (p[i] == 0) root = i;
		else edges[p[i]].eb(i);
	}

	vector<vector<int> > ans = dfs(root);

	for (int i = 0; i < (int)ans.size(); i++) {
		for (int x : ans[i]) {
			a[x] = i+1;
		}
	}

	if (!check(root)) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << '\n';
	return 0;
}