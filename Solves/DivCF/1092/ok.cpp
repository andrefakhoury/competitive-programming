#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100000000, MAXK = 10005, INF = 0x3f3f3f3f, SEED = 58, MOD = 1000000007;

void euclides(ll n, ll d, ll* i, ll* j, ll mod) {
	if (n%d == 0) {
		*j = 1;
		*i = 0;
	} else {
		euclides(d, n%d, i, j, mod);
		ll ti = *i;
		*i = *j;
		*j = (ti - (*j)*(n/d)+mod)%mod;
	}
}
int calcInverseMod(ll n, int mod) {
	ll i, j;
	euclides(mod, n, &i, &j, mod);
	return (j + mod)%mod;
}

ll ret;
vector<ll> divisors(ll n) {
	vector<ll> d;
	ll i;
	ret = 0;

	for (i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (i * i == n) {
				d.push_back(i);
				ret = (ret+i)%MOD;
			} else {
				d.push_back(i);
				d.push_back(n / i);

				ret = (ret+i)%MOD;
				ret = (ret+n/i)%MOD;
			}
		}
	}

	sort(d.begin(), d.end());
	return d;
}

ll chance[MAXN];
void solve(ll n, ll k, ll prev) {
	vector<ll> div = divisors(n);
	ll inv = calcInverseMod((ll)div.size(), MOD)%MOD;

	for (int i = 0; i < (int)div.size(); i++) {
		cout << div[i] << endl;

		chance[div[i]] = (chance[div[i]] + (inv*prev)%MOD)%MOD;
		if (k > 1) solve(div[i], k-1, (prev*inv)%MOD);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	printf("1/8 = %lld\n\n", calcInverseMod(8LL, MOD));


	cout << "1 * " << (9LL*calcInverseMod(16, MOD))%MOD << endl;
	cout << "2 * " << (3LL*calcInverseMod(16, MOD))%MOD << endl;
	cout << "3 * " << (3LL*calcInverseMod(16, MOD))%MOD << endl;
	cout << "6 * " << (1LL*calcInverseMod(16, MOD))%MOD << endl;

	ll ans = 0;
	ans = (ans + (ll)(1LL*(9LL*calcInverseMod(16, MOD))%MOD)%MOD)%MOD;
	ans = (ans + (ll)(2LL*(3LL*calcInverseMod(16, MOD))%MOD)%MOD)%MOD;
	ans = (ans + (ll)(3LL*(3LL*calcInverseMod(16, MOD))%MOD)%MOD)%MOD;
	ans = (ans + (ll)(6LL*(1LL*calcInverseMod(16, MOD))%MOD)%MOD)%MOD;

	cout << ans << endl;
}