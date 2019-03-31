#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define FF first
#define SS second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 10;

struct Edg {
	int v, id, f;

	Edg() {}
	Edg(int a, int b, int c) {
		v = a;
		id = b;
		f = c;
	}
};

int n, m;
vector<Edg> edges[MAXN];
bool visited[MAXN];
int ans[MAXN];

int color[MAXN];
bool vis[MAXN];

bool dfs(int u, int c) {
	if (color[u] != 0 && c != color[u]) return false;
	if (vis[u]) return true;

	vis[u] = true;
	color[u] = c;

	for (Edg p : edges[u]) {
		int v = p.v;
		int id = p.id;
		int f = p.f;

		bool ret = dfs(v, 3 - c);
		if (ret == false) return false;

		ans[id] = c == 1 ? f : !f;
	}

	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);

		edges[u].emplace_back(Edg(v, i, true));
		edges[v].emplace_back(Edg(u, i, false));
	}

	bool ret = dfs(1, 1);

	if (ret == false) return !printf("NO\n");
	else printf("YES\n");
	for (int i = 1; i <= m; i++) printf("%d", ans[i]);
	printf("\n");
}