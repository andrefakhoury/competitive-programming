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

const int MAXN = 5e5 + 5, INF = 0x3f3f3f3f;

vector<int> edges[MAXN];
vector<int> chosen[MAXN];
int ready[MAXN];

int main() {
	int n, m; rd(n, m);
	for (int i = 0; i < m; i++) {
		int u, v; rd(u, v);
		edges[u].eb(v);
		edges[v].eb(u);
	}

	auto imp = []() {
		puts("-1");
		exit(0);
	};

	for (int i = 1; i <= n; i++) {
		int x; rd(x);
		chosen[x].eb(i);
	}

	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		for (int u : chosen[i]) {
			set<int> alr = {0, n+1};
			for (int v : edges[u])
				alr.emplace(ready[v]);

			int what = -1;
			for (auto it = alr.begin(), nx = next(it); nx != alr.end(); it++, nx++) {
				if (1 + (*it) != *nx) {
					what = (*it) + 1;
					break;
				}
			}

			if (what != i) imp();
			ready[u] = i;
			ans.eb(u);
		}
	}

	for (int i : ans) printf("%d ", i);
	printf("\n");

}