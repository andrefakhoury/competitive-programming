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

int n;
char s[MAXN];

inline void _solve_(int __ntest__) {
	string s; cin >> s;
	int n = s.size();

	auto get = [&](int f, int r, int idx) {
		int cur = (s[idx]-'0') != f;
		for (int i = 0; i < n; i++) if (i != idx)
			cur += (s[i]-'0') != r;
		return cur;
	};

	int ans = n;
	ans = min(ans, get(1, 0, 0));
	ans = min(ans, get(1, 1, 0));
	ans = min(ans, get(0, 0, 0));
	ans = min(ans, get(0, 1, 0));

	ans = min(ans, get(1, 0, n-1));
	ans = min(ans, get(1, 1, n-1));
	ans = min(ans, get(0, 0, n-1));
	ans = min(ans, get(0, 1, n-1));

	auto get2 = [&](int l, int r, int x) {
		int cur = 0;
		for (int i = l; i <= r; i++)
			cur += (s[i] - '0') != x;
		return cur;
	};

	for (int i = 0; i < n; i++) {
		ans = min(ans, get2(0, i-1, 0) + get2(i, n-1, 0));
		ans = min(ans, get2(0, i-1, 0) + get2(i, n-1, 1));
		ans = min(ans, get2(0, i-1, 1) + get2(i, n-1, 0));
		ans = min(ans, get2(0, i-1, 1) + get2(i, n-1, 1));
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}
