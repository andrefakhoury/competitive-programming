#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 5;

struct DOHASH {
	ll hash;
	int n, k;

	DOHASH() {
		hash = n = k = 0;
	}

	DOHASH& operator+=(char c) {

	}
};

char s[MAXN];
DOHASH dist[MAXN];
vector<int> edges[MAXN];

bool vis[MAXN];
bool dfs(int u, int T) {
	vis[u] = true;
	bool ret = u == T;
	for (int v : edges[u]) if (!vis[v])
		ret |= dfs(v, T);
	return ret;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	scanf(" %s", s+1);

	while(m--) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].push_back(v);
	}

	int a, b; scanf("%d%d", &a, &b);
	if (!dfs(a, b)) return !printf("No way\n");

	dist[a] += s[a];
	priority_queue<pair<string, int>, vector<pair<string, int> >, greater<pair<string, int> > > pq;
	pq.emplace(dist[a], a);

	while(pq.size()) {
		string d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (d > dist[u]) continue;

		for (int v : edges[u]) {
			string w = dist[u] + s[v];
			if (dist[v].empty() || dist[v] > w) {
				dist[v] = w;
				pq.emplace(dist[v], v);
			}
		}
	}

	printf("%s\n", dist[b].c_str());
}