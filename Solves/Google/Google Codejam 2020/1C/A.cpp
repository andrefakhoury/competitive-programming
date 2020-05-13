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
	cout << "Case #" << __ntest__ << ": ";

	int x, y; cin >> x >> y;
	string s; cin >> s;

	int ans = INT_MAX;
	for (int k = 0, i = x, j = -y; k < (int) s.size(); k++) {
		int qtt = abs(i) + abs(j);

		if (k >= qtt) ans = min(ans, k);

		i += (s[k] == 'E') - (s[k] == 'W');
		j += (s[k] == 'S') - (s[k] == 'N');

		qtt = abs(i) + abs(j);
		if (k + 1 >= qtt) ans = min(ans, k + 1);
	}

	if (ans < INT_MAX) cout << ans << "\n";
	else cout << "IMPOSSIBLE\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int __T__; cin >> __T__;
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}