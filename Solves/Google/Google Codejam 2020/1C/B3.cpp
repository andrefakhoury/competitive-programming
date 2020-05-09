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

const int MAXN = 1e4, INF = 0x3f3f3f3f;
inline void _solve_(int __ntest__) {
	cout << "Case #" << __ntest__ << ": ";

	int u; cin >> u;

	map<int, set<string>> mp;

	set<char> all;

	map<string, int> fr;
	for (int i = 0; i < MAXN; i++) {
		int m; cin >> m;
		string q; cin >> q;

		if (q == "-1") {

		} else {
			for (char c : q) all.emplace(c);
			mp[m].emplace(q);
			fr[q++];
		}
	}

	set<char> used;

	string ans(10, 'A');
	for (int i = 1; i <= 9; i++) {
		for (auto ttt : mp[i]) {
			char x = ttt[0];
			if (!used.count(x)) {
				ans[i] = x;
				used.emplace(x);
				all.erase(x);
				break;
			}
		}
	}

	ans[0] = *all.begin();

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int __T__; cin >> __T__;
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}