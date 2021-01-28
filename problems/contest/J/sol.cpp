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

const int MAXN = 501;

const ll INF = 2e18;

ll p[MAXN];
ll memo[MAXN][MAXN];

inline void run_test() {
	int N; rd(N);
	for (int i = 1; i <= N; i++) rd(p[i]);

	for (int n = 0; n <= N; n++)
		for (int m = 0; m <= N; m++)
			memo[n][m] = INF;
	memo[0][0] = 0;

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= N; m++) {
			ll& ret = memo[n][m];
			for (int len = 1; len <= n; len++) {
				ret = min(ret, memo[n - len][m - 1] + p[len]);
			}
		}
	}

	int q; rd(q);
	while(q--) {
		int n, m; rd(n, m);
		if (memo[n][m] < INF) print(memo[n][m]);
		else print("impossible");
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

#ifndef LOCAL_PC
	freopen("jacking.in", "r", stdin);
#endif

	int T; rd(T);
	for (int cs = 1; cs <= T; cs++) {
		cout << "Case " << cs << ":\n";
		run_test();
	}
}