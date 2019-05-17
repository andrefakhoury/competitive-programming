#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 5;

pair<int, int> edge[MAXN];
int dist[MAXN], fdist[MAXN];
vector<pair<int, int> > bdist[MAXN];

void impossible() {
	cout << "No\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		edge[i] = {min(u, v), max(u, v)};
		dist[i] = edge[i].second - edge[i].first;
		dist[i] = min(dist[i], n - dist[i]);

		fdist[dist[i]]++;
		bdist[dist[i]].pb(edge[i]);

		cout << edge[i].first << "," << edge[i].second << ": " << dist[i] << endl;
	}

	int last = -1;
	for (int i = 1; i < MAXN; i++) {
		if (!fdist[i]) continue;

		if (last != -1 && last != fdist[i]) impossible();
		else last = fdist[i];

		sort(bdist[i].begin(), bdist[i].end());
	}

	cout << "Yes\n";
	return 0;
}