 #include <bits/stdc++.h>
 using namespace std;

 #define pb push_back
 #define eb emplace_back
 #define mk make_pair
 #define fi first
 #define se second
 #define mset(a, b) memset(a, b, sizeof(a))
 template<class T> void DBG(T&& x) { cerr << x << " "; }
 template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
 #define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl
 using ll = long long;
 using pii = pair<int, int>;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 #ifdef _WIN32
 #define getchar_unlocked _getchar_nolock
 #endif

 template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
 template<class num> inline void rd(num& x) {
 	char c, neg = 0; while(isspace(c = getchar_unlocked()));
 	if(!isdigit(c)) neg = (c == '-'), x = 0;
 	else x = c - '0';
 	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
 	x = neg ? -x : x; }
 template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

 const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

 map<int, int> all;
 void gen(int cur, int mask) {
 	int sum = 0;
 	for (int d = 1; d <= 9; d++) {
 		if (!((1 << d) & mask)) {
 			gen(cur * 10 + d, mask | (1 << d));
 		} else sum += d;
 	}
 	if (all.count(sum)) all[sum] = min(cur, all[sum]);
 	else all[sum] = cur;
 }

 inline void _solve_(int __ntest__) {
 	int n; rd(n);
 	if (all.count(n)) printf("%d\n", all[n]);
	else puts("-1");
 }

 int main() {
 	gen(0, 0);
 	int __T__; rd(__T__);
 	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
 	return 0;
 }