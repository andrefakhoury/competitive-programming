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

const int MAXN = 201;
const int MAXX = 2e3 + 1;
int n, m, q;

int f[MAXN][MAXN][MAXX];

inline void run_test() {
	rd(n, m, q);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x; rd(x);
			for (int k = 1; k < MAXX; k++) {
				f[i][j][k] = (k == x ? 1 : 0) + f[i-1][j][k] + f[i][j-1][k] - f[i-1][j-1][k];
			}
		}
	}
	while(q--) {
		int a, b, c, d; rd(a, b, c, d);
		int len = (c - a + 1) * (d - b + 1), cur = 0;
		if (len % 2 == 0) len = len / 2 + 1;
		else len = (len + 1) / 2;
		for (int x = 1; x < MAXX; x++) {
			cur += f[c][d][x] - f[c][b-1][x] - f[a-1][d][x] + f[a-1][b-1][x];
			if (cur >= len) {
				print(x);
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

#ifndef LOCAL_PC
	freopen("important.in", "r", stdin);
#endif

	int T; rd(T);
	for (int cs = 1; cs <= T; cs++) {
		cout << "Case " << cs << ":\n";
		run_test();
	}
}