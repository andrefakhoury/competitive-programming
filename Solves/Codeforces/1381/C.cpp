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
#ifndef __linux
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;
inline void _solve_(int __ntest__) {
	int n, x, y; rd(n, x, y);
	map<int, int> f;
	vector<pii> a(n);

	int X = x, Y = y;

	vector<vector<int>> where(n+2);
	for (int i = 0; i < n; i++) {
		rd(a[i].fi);
		a[i].se = i;
		f[a[i].fi]++;
		where[a[i].fi].pb(i);
	}


	int nothing = 1;
	for (int i = 1; i <= n + 1; i++) if (!f.count(i)) nothing = i;

	set<pii> st;
	for (auto p : f) st.emplace(p.se, p.fi);

	y -= x;
	vector<int> ans(n);
	while(x--) {
		pii val = *st.rbegin();
		st.erase(*st.rbegin());
		int who = where[val.se].back();
		where[val.se].pop_back();
		ans[who] = val.se;
		f[val.se]--;
		if (f[val.se] == 0) f.erase(val.se);
		else {
			st.emplace(val.fi - 1 , val.se);
		}
	}

	vector<pii> utilize;
	while(st.size()) {
		pii val = *st.begin();
		st.erase(st.begin());
		int who = where[val.se].back();
		where[val.se].pop_back();
		utilize.eb(val.se, who);
		if (val.fi != 1) {
			st.emplace(val.fi - 1, val.se);
		}
	}

	queue<pii> q;

	int N = utilize.size();
	sort(utilize.begin(), utilize.end(), [&](pii a, pii b) {
		return f[a.fi] > f[b.fi];
	});
	// reverse(utilize.begin(), utilize.end());

	vector<bool> blz(N);
	for (int i = 0; y > 0 && i < N+N; i++) {
		if (!blz[i%N] && q.size() && q.front().fi != utilize[i%N].fi) {
			blz[i%N] = true;
			ans[q.front().se] = utilize[i%N].fi;
			q.pop();
			y--;
		}

		if (i < N) q.emplace(utilize[i]);
	}

	for (int& i : ans) i = i ? i : nothing;
		
	int cnt = 0;
	map<int, int> f1;
	for (pii i : a) f1[i.fi]++;
	for (int i : ans) {
		if (f1[i]) {
			cnt++;
			f1[i]--;
		}
	}
	int equ = 0;
	for (int i = 0; i < n; i++)
		equ += a[i].fi == ans[i];

	if (equ != X or cnt != Y) puts("NO");
	else {
		puts("YES");
		for (int i : ans) printf("%d ", i ? i : nothing);
		printf("\n");
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}