#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) cout.flush(); fflush(stdout); fprintf(stderr, args)
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
	x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

inline void _solve_() {
	int n, m; rd(n, m);

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			rd(a[i][j]);
		}
	}

	set<pii> rw_o, cl_o;
	set<pii, greater<pii>> rw_d, cl_d;
	set<pii> all;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		rw_o.emplace(i, j);
		rw_d.emplace(i, j);
		cl_o.emplace(j, i);
		cl_d.emplace(j, i);
		all.emplace(i, j);
	}

	ll ans = 0;
	while(true) {
		vector<pii> elim;
		for (auto pp : all) {
			int i = pp.fi, j = pp.se;

			ans += a[i][j];

			ll sum = 0, qtt = 0;
			auto it_1 = rw_o.upper_bound(mk(i, j));
			if (it_1 != rw_o.end() && it_1->fi == i) {
				sum += a[it_1->fi][it_1->se];
				qtt++;
			}

			auto it_2 = rw_d.upper_bound(mk(i, j));
			if (it_2 != rw_d.end() && it_2->fi == i) {
				sum += a[it_2->fi][it_2->se];
				qtt++;
			}

			auto it_3 = cl_o.upper_bound(mk(j, i));
			if (it_3 != cl_o.end() && it_3->fi == j) {
				sum += a[it_3->se][it_3->fi];
				qtt++;
			}

			auto it_4 = cl_d.upper_bound(mk(j, i));
			if (it_4 != cl_d.end() && it_4->fi == j) {
				sum += a[it_4->se][it_4->fi];
				qtt++;
			}

			if (qtt && a[i][j] * qtt < sum) elim.eb(i, j);
		}

		for (auto p : elim) {
			a[p.fi][p.se] = 0;
			rw_o.erase(p);
			rw_d.erase(p);
			cl_o.erase({p.se, p.fi});
			cl_d.erase({p.se, p.fi});
			all.erase(p);
		}

		if (elim.empty()) break;
	}

	printf("%lld\n", ans);
	
}

int main() {
	int __T__; rd(__T__);
	for (int xx = 1; xx <= __T__; xx++) {
		printf("Case #%d: ", xx);
		_solve_();
	}
	return 0;
}