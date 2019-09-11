#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;

const int MAXN = 3e5 + 5;

struct HASH {
	unsigned long long fi, se;

	HASH() {
		fi = se = 0;
	}

	char* str() {
		
	}

	bool operator>(HASH const& h) const {
		return fi == h.fi ? se > h.se : fi > h.fi;
	}

	bool operator<(HASH const& h) const {
		return fi == h.fi ? se < h.se : fi < h.fi;
	}

	HASH& operator+(char c) {
		fi ^= (c << 13) + fi*0x123affb3141 + 0xf3f4f1fa75fb*c + 0xaf;
		se ^= (c << 30) + se*0xdeadbeef123 + 0x12cdef1e7571*c + 0xfa;
	}

	bool empty() {
		return fi == 0 && se == 0;
	}
};

int n, m;
vector<int> edges[MAXN];
HASH dist[MAXN];
char s[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	scanf(" %s", s+1);

	while(m--) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].push_back(v);
	}

	int a, b; scanf("%d%d", &a, &b);
	priority_queue<pair<HASH, int> > pq;
	dist[a] = dist[a] + s[a];
	pq.emplace(dist[a], a);

	while(pq.size()) {
		int u = pq.top().second;
		HASH d = pq.top().first;
		pq.pop();

		if (d > dist[u]) continue;
		for (int v : edges[u]) {
			if (dist[v].empty() || dist[v] > dist[u] + s[v]) {
				dist[v] = dist[u] + s[v];
				pq.emplace(dist[v], v);
			}
		}
	}

	printf("%s\n", dist[b].empty() ? "No way" : dist[b].str());
}