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
const int MOD = 1e9 + 7;

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
	return (1ll * x * y % MOD + MOD) % MOD;
}

int main() {
	int n, k; rd(n, k);
	vector<int> a(n);

	int P = 0, N = 0, Z = 0;
	for (int& i : a) rd(i), P += i > 0, N += i < 0, Z += i == 0;

	int ans = 1;

	bool neg = P < k;
	if (neg && P == 0 && k%2 == 0) neg = false;
	if (neg && P > 0) neg = false;

	if (neg) {
		if (Z) ans = 0;
		else {
			sort(a.rbegin(), a.rend());
			for (int i = 0; i < k; i++)
				ans = mul(ans, a[i]);
		}
	} else {
		sort(a.begin(), a.end());
		
		for (int l = 0, r = n-1; k > 0;) {
			if (k == 1) {
				ans = mul(ans, a[r--]);
				k--;
			} else {
				if (1ll * a[l] * a[l+1] >= 1ll * a[r] * a[r-1]) {
					ans = mul(ans, a[l]);
					ans = mul(ans, a[l+1]);
					l += 2;
					k -= 2;
				} else {
					ans = mul(ans, a[r]);
					r--;
					k--;
				}
			}
		}
	}

	printf("%d\n", ans);

}