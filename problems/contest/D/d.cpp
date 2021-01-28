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

const int MOD = 1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

int sub(int x, int y) {
	x -= y;
	if (x < 0) x += MOD;
	return x;
}

int mul(int x, int y) {
	return 1ll * x * y % MOD;
}

const int MAXN = 5e3 + 5;
int a[MAXN];
int qtt[MAXN]; // qtt[i] is the number of times i appear on a path
int memo[MAXN][MAXN];

inline void run_test(int test_number) {
	int n, k, q; rd(n, k, q);
	for (int i = 1; i <= n; i++) rd(a[i]);

	int ans = 0;

	for (int i = 1; i <= n; i++) memo[i][0] = 1;
	for (int s = 1; s <= k; s++) {
		for (int i = 1; i <= n; i++) {
			for (int j : {i - 1, i + 1}) if (j >= 1 && j <= n) {
				memo[i][s] = add(memo[i][s], memo[j][s-1]);
				qtt[i] = add(qtt[i], memo[j][s-1]);
				qtt[j] = add(qtt[j], memo[i][s-1]);
			}
			DBG(i, s, memo[i][s]);
		}
	}

	vector<pii> qry(q);
	vector<int> aa(n + 1);

	for (int i = 1; i <= n; i++) aa[i] = a[i];
	for (int i = 0; i < q; i++) rd(qry[i].fi, qry[i].se);

	vector<int> qtt = {0, 6, 9, 11, 9, 6};
	for (int x1 = 1; x1 <= 10; x1++) {
		for (int x2 = x1; x2 <= 12; x2++) {
			for (int x3 = x2; x3 <= 20; x3++) {
				vector<int> a = aa;
				vector<int> qtt = {0, x1, x2, x3, x2, x1};
				ans = 0;


				for (int i = 1; i <= n; i++) {
					ans = add(ans, mul(a[i], qtt[i]));
				}
				
				vector<int> anse = {157,147,207,227,227};
				vector<int> curas;

				for (int i = 1; i <= q; i++) {
					int id, val; id = qry[i-1].fi, val = qry[i-1].se;
					ans = sub(ans, mul(qtt[id], a[id]));
					a[id] = val;
					ans = add(ans, mul(qtt[id], a[id]));
					// print(ans);
					curas.pb(ans);
				}
				if (curas == anse) {
					DBG(x1, x2, x3);
				}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}