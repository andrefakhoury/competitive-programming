#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

struct Node {
	int h, p, x;

	bool operator<(Node const& rhs) const {
		return h < rhs.h;
	}
};

int p[maxn];
vector<int> v[maxn];
Node h[maxn];
priority_queue<Node> pq;

Node dfs(int x) {
	h[x] = {1, x, -1};

	for (int u : v[x]) {
		auto p = dfs(u);
		h[x] = max(h[x], Node{p.h+1, x, u});
	}

	return h[x];
}

void dfs2(int x) {
	for (int u : v[x]) {
		if (u != h[x].x) {
			pq.push(h[u]);
		}
	}
	if (h[x].x != -1) dfs2(h[x].x);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		v[p[i]].push_back(i);
	}

	dfs(1);


	pq.push(h[1]);

	int ans = 0;
	while (k--) {
		auto x = pq.top();
		pq.pop();

		ans += x.h;

		dfs2(x.p);
	}

	cout << ans << "\n";
	return 0;
}