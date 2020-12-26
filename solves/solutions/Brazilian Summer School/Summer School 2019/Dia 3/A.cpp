#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

ll fast_exp(ll x, ll y, ll MOD) {
	x%=MOD;

	ll ans = 1;
	while (y > 0) {
		if (y & 1LL) ans = (ans * x) % MOD;
		y >>= 1LL;
		x = (x*x) % MOD;
	}

	return ans % MOD;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL);

	ll b, p, m;
	while(~scanf("%lld%lld%lld", &b, &p, &m)) {
		printf("%lld\n", fast_exp(b, p, m));
	}


	return 0;
}