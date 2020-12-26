#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 200;
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
};

vector<int> inp[MAXN];
int lang[MAXN];

int main() {
	UF_union uf;
	int n, m; scanf("%d%d", &n, &m);
	uf.init(n);

	int ans = 0;
	int chosen = -1;

	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		while(k--) {
			int x; scanf("%d", &x);
			inp[i].pb(x);
			chosen = x;
		}

		if (inp[i].size() != 0) lang[i] = inp[i][0];
		for (int j = 0; j < (int)inp[i].size() - 1; j++)
			uf.merge(inp[i][j], inp[i][j+1]);
	}

	if (chosen == -1) return !printf("%d\n", n);

	for (int i = 1; i <= n; i++) {
		if (lang[i] == 0) {
			ans++;
			lang[i] = chosen;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (!uf.same(lang[i], lang[j])) {
				ans++;
				uf.merge(lang[i], lang[j]);
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}