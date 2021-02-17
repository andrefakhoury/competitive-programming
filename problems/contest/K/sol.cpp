#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) print(__VA_ARGS__), print('\n')

const int MAXN = 6e4 + 5;

bitset<MAXN> vis[63][63];
int n, a[63];

vector<pii> all;
void go(int i, int k, int d) {
	if (d >= MAXN || vis[i][k][d]) return;
	vis[i][k][d] = true;

	if (i < n) {
		go(i + 1, k, d);
		go(i + 1, k + 1, d + a[i]);
	} else if (k) all.eb(k, d);
}


inline void run_test(int test_number) {
	int d; rd(n, d);
	for (int i = 0; i < n; i++) rd(a[i]);

	all.reserve(n * d);
	go(0, 0, 0);

	double ans = -1;
	for (auto [k, x] : all) {
		if (x + 10 >= d && x - 5 * (k - 1) <= d) {
			double cur = (10 + x - d) / (k + 1.0);
			ans = max(ans, clamp(cur, 0., 5.));
		}
	}

	if (ans >= 0) cout << fixed << setprecision(10) << ans << "\n";
	else cout << "impossible\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}