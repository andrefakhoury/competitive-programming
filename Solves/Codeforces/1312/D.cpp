#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;
const int MOD = 998244353;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int add(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if (x < 0) x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return ll(x) * y % MOD;
}

inline int inv(int x) {;
	int y = MOD-2;
	int res = 1;
	while (y > 0) {
		if (y & 1) res = mul(res, x);
		x = mul(x, x);
		y >>= 1;
	}
	return res;
}

inline int divi(int x, int y) {
	return mul(x, inv(y));
}

int fat[MAXN];
inline void init() {
	fat[0] = 1;
	for (int i = 1; i < MAXN; i++) fat[i] = mul(fat[i-1], i);
}

inline int nck(int n, int k) {
	if (n < k) return 0;
	return divi(fat[n], mul(fat[n-k], fat[k]));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	if (n == 2) {
		cout << 0 << endl;
		return 0;
	}

	init();

	int sum = 0;
	for (int j = 0; j < m; j++) {
		if (j - n + 2 >= 0) sum = add(sum, divi(fat[j], fat[j - n + 2]));
	}

	int ans = 0;
	for (int i = 1; i < n-1; i++) {
		if (n - i - 2 >= 0)
			ans = add(ans, mul(divi(i, mul(fat[i], fat[n-i-2])), sum));
	}

	cout << ans << '\n';

	return 0;
}