#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;

vector<int> edges[MAXN];
bool vis[MAXN];

int main() {
	//ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; scanf("%d%d", &n, &m);
	while(m--) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].pb(v);
		edges[v].pb(u);
	}

	vector<int> ans;

	vis[1] = true;
	priority_queue<int> pq;
	pq.push(-1);

	while(pq.size()) {
		int u = -pq.top();
		pq.pop();
		ans.pb(u);

		for (int v : edges[u]) {
			if (!vis[v]) {
				vis[v] = true;
				pq.push(-v);
			}
		}
	}

	for (int a : ans) printf("%d ", a);
	printf("\n");
	
	return 0;
}