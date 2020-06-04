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

inline int ask(vector<int> v) {
	cout << "? " << v.size() << " ";
	for (int i : v) cout << i << " ";
	cout << endl;
	cout.flush();

	int x; cin >> x;
	if (x == -1) exit(0);

	return x;
}

inline int ask(vector<vector<int>>& all, int l, int r) {
	vector<int> cur;
	for (int i = l; i <= r; i++) {
		for (int xx : all[i]) cur.eb(xx);
	}
	return ask(cur);
}

inline void guess(vector<int> ans) {
	cout << "! ";
	for (int x : ans) cout << x << " ";
	cout << endl;
	cout.flush();

	string sss; cin >> sss;
	if (sss != "Correct") exit(0);
}

inline void _solve_(int __ntest__) {
	int n, k; cin >> n >> k;

	vector<vector<int>> v(k);
	for (auto& a : v) {
		int kk; cin >> kk;
		a.resize(kk);
		for (int& p : a) cin >> p;
	}

	auto notv = [&](vector<int> a) {
		set<int> ret;
		for (int i = 1; i <= n; i++) ret.emplace(i);
		for (int x : a) ret.erase(x);
		vector<int> rrt;
		for (int x : ret) rrt.eb(x);
		return rrt;
	};

	int mx = ask(notv({}));

	int lo = 0, hi = k-1, mi;
	while(lo < hi) {
		mi = (lo + hi) / 2;
		int curr = ask(v, lo, mi);
		if (curr == mx) hi = mi;
		else lo = mi + 1;
	}

	vector<int> ans(k, mx);
	ans[lo] = ask(notv(v[lo]));
	guess(ans);
}

int main() {	
	int __T__; cin >> __T__;
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}