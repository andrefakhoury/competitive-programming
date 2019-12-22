#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 500000;
const int INF = 0x3f3f3f3f;

struct UF_union {
	int par[MAXN], siz[MAXN], n;

	void init(int a) {
		n = a;
		for (int i = 0; i < MAXN; i++) {
			par[i] = i;
			siz[i] = 1;
		} 
	}

	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	void merge(int u, int v) {
		int a = find(u);
		int b = find(v);
		if (siz[a] > siz[b]) swap(a, b);
		par[a] = b;
		siz[b] += siz[a];
	}

	int mesmo(int x) {
		return x;
	}

	int oposto(int x) {
		return n + x;
	}

	bool mergeSame(int u, int v) {
		if (find(oposto(u)) == find(v)) return false;
		if (find(oposto(v)) == find(u)) return false;

		merge(u, v);
		merge(oposto(u), oposto(v));

		return true;
	}

	bool mergeOposto(int u, int v) {
		if (find(u) == find(v)) return false;
		if (find(oposto(u)) == find(oposto(v))) return false;

		merge(u, oposto(v));
		merge(v, oposto(u));

		return true;
	}

	int getRelation(int u, int v) {
		if (find(u) == find(v)) return 1;
		if (find(u) == find(oposto(v))) return 2;
		if (find(v) == find(oposto(u))) return 2;
		return 3;
	}
};

unordered_map<string, int> dict;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		dict[s] = i;
	}

	UF_union uf;
	uf.init(n);

	for (int i = 1; i <= m; i++) {
		int op; cin >> op;
		string x, y; cin >> x >> y;

		if (op == 1) {
			cout << (uf.mergeSame(dict[x], dict[y]) ? "YES\n" : "NO\n");
		} else {
			cout << (uf.mergeOposto(dict[x], dict[y]) ? "YES\n" : "NO\n");
		}
	}

	for (int i = 1; i <= q; i++) {
		string x, y; cin >> x >> y;
		cout << uf.getRelation(dict[x], dict[y]) << "\n";
	}

	return 0;
}