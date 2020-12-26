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
const int MAXN = 2e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int cost[MAXN];
bool vis[MAXN];
vector<pii> edges[MAXN];

void dfs(int u) {
	vis[u] = true;

	for (auto v : edges[u]) if (!vis[v.fi]) dfs(v.fi);
	for (auto v : edges[u]) cost[u] += cost[v.fi] * v.se;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	map<string, int> id;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		id[s] = id.size();
		cin >> cost[id[s]];
	}

	set<string> st;

	string s1;
	while(cin >> s1) {
		st.emplace(s1);

		string s2; cin >> s2;
		int u, v, w; cin >> w;

		if (id.count(s1)) u = id[s1];
		else u = id[s1] = id.size();

		if (id.count(s2)) v = id[s2];
		else v = id[s2] = id.size();

		edges[u].eb(v, w);
	}

	for (int i = 0; i < (int)id.size(); i++)
		if (!vis[i]) dfs(i);

	for (string s : st) cout << s << " " << cost[id[s]] << '\n';

	return 0;
}