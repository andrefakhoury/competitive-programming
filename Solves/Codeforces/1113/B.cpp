#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> divisors(ll n) {
	vector<ll> ret;

	for (int i = 1; i * i <= n; i++) {
		if (n%i == 0) {
			if (i * i != n) ret.push_back(n/i);
			ret.push_back(i);
		}
	}

	return ret;
}

int main() {
	ll n; scanf("%lld", &n);
	vector<ll> a(n);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	sort(a.begin(), a.end());

	ll sum = 0;
	for (int i = 0; i < n; i++) sum += a[i];

	ll ans = sum;
	for (int i = 1; i < n; i++) {
		vector<ll> div = divisors(a[i]);

		for (ll d : div) {
			ll first = a[0];
			ll actual = a[i];

			ans = min(ans, sum - first - actual + first*d + actual/d);
		}
	}

	printf("%lld\n", ans);

	return 0;
}