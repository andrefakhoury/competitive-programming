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
#define print(...) { print(__VA_ARGS__); print('\n'); }

const int MOD = 998244353;
inline int add(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}
inline void iadd(int& x, int y) { x = add(x, y); }
inline int sub(int x, int y) {
	x -= y;
	if (x < 0) x += MOD;
	return x;
}
inline void isub(int& x, int y) { x = sub(x, y); }
inline int mul(int x, int y) {
	return 1ll * x * y % MOD;
}
inline void imul(int& x, int y) { x = mul(x, y); }
inline int fpow(int x, int y) {
	int r = 1;
	for (; y > 0; x = mul(x, x), y /= 2) if (y%2) r = mul(r, x);
	return r;
}
inline int divi(int x, int y) {
	return mul(x, fpow(y, MOD-2));
}
inline void idivi(int& x, int y) { x = divi(x, y); }

int n, m, k;
void brute(int i, int j, vector<vector<int>>& cur, vector<int>& qtt) {
	if (j == m) return brute(i + 1, 0, cur, qtt);
	auto cnt = [](vector<vector<int>>& cur)->int {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				bool has = false;
				has |= i > 0 && cur[i-1][j] == cur[i][j];
				has |= j > 0 && cur[i][j-1] == cur[i][j];
				has |= j == 0 && m == 2 && i > 0 && cur[i-1][j+1] == cur[i][j] && cur[i][j+1] == cur[i][j];
				ans += !has;
			}
		}
		return ans;
	};
	if (i == n) {
		qtt[cnt(cur)]++;
		return;
	}
	for (int x = 1; x <= k; x++) {
		cur[i][j] = x;
		brute(i, j + 1, cur, qtt);
	}
}

inline void run_test(int test_number) {
	rd(m, n, k);
	DBG(m, n, k);

	int N = max(n * m, k);

	vector<int> fac(N + 1);
	fac[0] = 1;
	for (int i = 1; i <= N; i++) fac[i] = mul(fac[i-1], i);

	auto nck = [&fac](int n, int k) {
		if (k > n) return 0;
		return divi(fac[n], mul(fac[k], fac[n - k]));
	};

	if (k == 1) {
		print(1);
		return;
	}

	if (m == 2) {
		int num = 0, den = 0;
		for (int i = 1; i <= n; i++) {
			int cur = mul(nck(n-1, i-1), mul(k, fpow(k - 1, i - 1)));
			iadd(num, mul(i, cur));
			iadd(den, cur);
			DBG(i, cur);
		}
		print(divi(num, den));
	} else {
		int num = 0, den = 0;
		for (int i = 1; i <= n * m; i++) {
			int s1 = mul(k, fpow(k - 1, i - 1));
			int s2 = nck(n - 1, i - 1);
			int cur = mul(s1, s2);

			iadd(num, mul(i, cur));
			iadd(den, cur);
		}
		print(divi(num, den));
	}

	vector<vector<int>> grid(n, vector<int>(m));
	vector<int> qtt(n * m + 1);
	brute(0, 0, grid, qtt);
	int num = 0, den = 0;
	for (int i = 0; i <= n * m; i++) {
		num = add(num, mul(i, qtt[i]));
		den = add(den, qtt[i]);
		DBG(i, qtt[i]);
	}
	print(divi(num, den));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}

// 2 2 2
//[i, qtt[i]]: 1 2
//[i, qtt[i]]: 2 12
//[i, qtt[i]]: 3 0
//[i, qtt[i]]: 4 2


//[m, n, k]: 2 5 3
//[i, qtt[i]]: 1 3
//[i, qtt[i]]: 2 270
//[i, qtt[i]]: 3 2712
//[i, qtt[i]]: 4 8556
//[i, qtt[i]]: 5 14160
//[i, qtt[i]]: 6 14676
//[i, qtt[i]]: 7 10692
//[i, qtt[i]]: 8 5550
//[i, qtt[i]]: 9 1944
//[i, qtt[i]]: 10 486










// 1 4 2: 499122179

/**
[i, qtt[i]]: 0 0
[i, qtt[i]]: 1 2
[i, qtt[i]]: 2 6
[i, qtt[i]]: 3 6
[i, qtt[i]]: 4 2

 /3 * 2

[i, qtt[i]]: 1 3
[i, qtt[i]]: 2 54
[i, qtt[i]]: 3 432
[i, qtt[i]]: 4 2016
[i, qtt[i]]: 5 6048
[i, qtt[i]]: 6 12096
[i, qtt[i]]: 7 16128
[i, qtt[i]]: 8 13824
[i, qtt[i]]: 9 6912
[i, qtt[i]]: 10 1536

1: k
2: C()  k * (k - 1) * (n - 1)
3: C(n-1, 3) * (C(k, 2) + C(k, 3))
3: C(n, 2) * () + C(n, 3) * ()
 */