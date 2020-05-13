#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) { cout.flush(); fflush(stdout); fprintf(stderr, args); }
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;
inline void _solve_(int __ntest__) {
	int x, y; rd(x, y);
	pii P = {x, y}, O = {0, 0};

	queue<pii> q;
	q.emplace(P);
	map<pii, pii> par;
	map<pii, int> cur;
	cur[P] = 0;
	par[P] = P;

	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};

	while(q.size()) {
		pii u = q.front();
		q.pop();
		if (u == O) break;
		ll d = 1ll << (cur[u]);
		if (cur[u] > 10) continue;
		for (int k = 0; k < 4; k++) {
			pii v = u;
			v.fi += (1ll << cur[u]) * dx[k];
			v.se += (1ll << cur[u]) * dy[k];
			if (!cur.count(v)) {
				par[v] = u;
				cur[v] = cur[u] + 1;
				q.emplace(v);
			}
		}
	}

	printf("Case #%d: ", __ntest__);

	if (par.count(O)) {
		string ans;
		while(O != P) {
			pii v = par[O];
			if (v.fi > O.fi) ans += 'E';
			else if (v.fi < O.fi) ans += 'W';
			else if (v.se > O.se) ans += 'N';
			else if (v.se < O.se) ans += 'S';
			O = v;
		}

		reverse(ans.begin(), ans.end());
		printf("%s\n", ans.c_str());


	} else {
		printf("IMPOSSIBLE\n");
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}	