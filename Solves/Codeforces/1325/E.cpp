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
const int MAXN = 1e6 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[MAXN];
vector<int> divi[MAXN];

inline void answer(int x) {
	cout << x << "\n";
	exit(0);
}

inline void getdiv(int ind) {
	int n = a[ind];
	vector<int>& ret = divi[ind];
	for (int i = 2; i * i <= n; i++) {
		while(n%i == 0) {
			ret.pb(i);
			n /= i;
		}
	}
	if (n > 1) ret.pb(n);
	
	if (n == 1) answer(1);

	assert(ret.size() <= 2);
}

inline int normalize(int n) {
	for (int i = 2; i * i <= n; i++)
		while(n % (i*i) == 0) n /= i*i;
	return n;
}

vector<int> edges[MAXN];
int dist[MAXN];
int par[MAXN];
inline int bfs(int s) {
	memset(dist, -1, sizeof dist);
	memset(par, -1, sizeof par);
	queue<int> q;
	q.push(s);
	dist[s] = 0;

	int ret = INF;
	while(q.size()) {
		int u = q.front();
		q.pop();

		for (int v : edges[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				par[v] = u;
				q.push(v);
			} else if (par[u] != v) {
				ret = min(ret, dist[u] + dist[v] + 1);
			}
		}
	}

	return ret;
}

int cnt[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = normalize(a[i]);
		getdiv(i);
		cnt[a[i]]++;
	}

	for (int i = 1; i <= n; i++) if (cnt[a[i]] >= 2) answer(2);

	for (int i = 1; i <= n; i++) {
		vector<int>& v = divi[i];

		if (v.size() == 1) {
			edges[v.back()].pb(1);
		} else {
			edges[v.back()].pb(v.front());
			edges[v.front()].pb(v.back());
		}
	}

	int ans = INF;
	for (int i = 1; i <= 1000; i++) {
		ans = min(ans, bfs(i));
	}

	answer(ans < INF ? ans : -1);
	return 0;
}