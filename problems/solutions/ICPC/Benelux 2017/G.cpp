#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

map<vector<int>, int> memo;

vector<int> go(vector<int> a) {
	if (a.empty()) return a;
	sort(a.begin(), a.end());
	vector<int> ret;
	for (int i : a) if (i) ret.pb(i);
	return ret;
}
 
vector<int> go(vector<int> a, int i, int j, int k) {
	a[i] -= k;
	a[j] += k;
	return go(a);
}

int n;

int solve(vector<int> a) {
	vector<vector<int>> q = {a};
	memo[a] = 0;

	while(q.size()) {
		vector<int> v = q.back();
		q.pop_back();

		if (v.empty()) return memo[v];

		int cur = memo[v];
		for (int i = 0; i < (int) v.size(); i++) {
			if (v[i] <= 0) continue;
			for (int j = 0; j < (int) v.size(); j++) {
				if (v[j] >= 0) continue;

				for (int k = 1; k <= min(a[i], -a[j]); k++) {
					auto nxt = go(v, i, j, k);
					if (memo.count(nxt)) continue;
					memo[nxt] = cur + 1;
					q.eb(nxt);
				}
			}
		}
	}

	assert(0);
}

int main() {
	int m; rd(n, m);
	vector<int> sld(n);
	while(m--) {
		int u, v, w; rd(u, v, w);
		sld[u] -= w;
		sld[v] += w;
	}

	printf("%d\n", solve(go(sld)));
}