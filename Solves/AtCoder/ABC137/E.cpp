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
const int MAXN = 2500 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> edges[MAXN];
ll dist[MAXN];

inline int bellmanford(int n) {
	memset(dist, 0x3f, sizeof dist);

	for (int k = 1; k < n; k++) {
		bool ok = true;
		for (int u = 1; u <= n; u++) {
			if (dist[v] > dist[u] + w) {

			}
		}
	}

	for (int cnt = 1; cnt <= n-1; cnt++) {
		bool converged = true;
		for (int u = 1; u <= n; u++) {
			for (int v : edges[u]) {
				if (dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					converged = false;
				}
			}
		}
		if (converged) break;
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL);
	

	return 0;
}