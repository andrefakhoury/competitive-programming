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
const int MAXN = 1e6 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;

vector<int> gift[MAXN];
ll qtt[MAXN];

// a^b mod m
inline ll powerMod(ll a, ll b, ll m) {
	a %= m;
	b %= m-1; // if m is prime
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

inline ll invMod(ll x) {
	return powerMod(x, MOD-2, MOD);
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		while(k--) {
			int x; scanf("%d", &x);
			gift[i].eb(x);
			qtt[x]++;
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int k = gift[i].size();
		ll cur = (invMod(n) * invMod(k)) % MOD;
		
		for (int j = 0; j < k; j++) {
			int g = gift[i][j];
			ans = (ans + (((cur * qtt[g]) % MOD) * invMod(n)) % MOD) % MOD;
		}
	}

	cout << ans << '\n';

	return 0;
}