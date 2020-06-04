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
inline void _solve_(int __ntest__) {
	unsigned long long a, b; rd(a, b);

	unsigned long long A = a, B = b;
	while(A%2 == 0) A /= 2;
	while(B%2 == 0) B /= 2;

	if (A != B) puts("-1");
	else {
		int ans = 0;

		while(4 * a < b) {
			ans++;
			a *= 8;
		}

		while(2 * a < b) {
			ans++;
			a *= 4;
		}

		while(a < b) {
			ans++;
			a *= 2;
		}

		int cnt = 0;
		while(a > b) {
			cnt++;
			a /= 2;
		}

		ans += cnt/3;
		cnt %= 3;
		ans += cnt/2;
		cnt %= 2;
		ans += cnt;

		printf("%d\n", ans);
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}