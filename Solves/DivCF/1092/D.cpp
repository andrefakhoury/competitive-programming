#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const ll MAXN = 100000000, MAXK = 10005, INF = 0x3f3f3f3f, MOD = 1000000007;

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
ll calcInverseMod(ll n, ll mod) {
	ll i, j;
	euclides(mod, n, &i, &j, mod);
	return ((j + mod)%mod + mod)%mod;
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
	ll sum = (inv*prev)%MOD;

	// for (int i = 0; i < div.size(); i++) cout << div[i] << " ";
	// cout << endl;

	for (ll i = 0; i < (ll)div.size(); i++) {
		// cout << div[i] << " -> + " << sum << endl;

		if (prev > 1) chance[div[i]] = (chance[div[i]] + sum)%MOD;
		if (k > 1) solve(div[i], k-1, sum);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	ll n, k; cin >> n >> k;
	solve(n, k, 1);

	ll ans = 0;
	for (ll i = 0; i < MAXN; i++) {
		if (chance[i]) ans = (ans + (i*chance[i])%MOD)%MOD;
		// if (chance[i]) cout << i << " * " << chance[i] << endl;
	}

	cout << ans << endl;
	return 0;
}
//1/8 = 125000001
//1/2 = 500000004
//1/4 = 250000002

/*
1 * 62500001
2 * 687500005
3 * 687500005
6 * 562500004
875000008
*/