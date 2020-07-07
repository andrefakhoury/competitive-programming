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

const int MAXN = 3e5 + 5, INF = 0x3f3f3f3f;

int a[MAXN];
int mn[MAXN];
int mx[MAXN];

inline void _solve_(int __ntest__) {
	int n; rd(n);
	for (int i = 1; i <= n; i++) rd(a[i]);

	mx[n+1] = 0;
	for (int i = n; i >= 1; i--) mx[i] = max(mx[i+1], a[i]);
	mn[0] = n+1;
	for (int i = 1; i <= n; i++) mn[i] = min(mn[i-1], a[i]);

	mx[n+1] = n+1;
	mn[0] = 0;

	bool ans = true;
	for (int i = 1; ans && i <= n; i++) {
		ans &= ((a[i] > mn[i] or a[i] < mx[i]) && mn[i-1] < mx[i+1]);
	}

	bool any = false;
	for (int i = 1; i < n; i++) any |= a[i] < a[i+1];
	ans &= any;

	printf("%s\n", ans ? "YES" : "NO");
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}