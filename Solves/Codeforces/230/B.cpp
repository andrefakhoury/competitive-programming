#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

set<ll> ans;
bool notPrime[MAXN];

void crivo() {
	for (ll i = 2; i < MAXN; i++) {
		if (!notPrime[i]) {
			ans.insert(i*i);
			for (ll j = 2*i; j < MAXN; j += i) notPrime[j] = true;
		}
	}
}

int main() {
	crivo();
	ll n; cin >> n;
	while (n--) {
		ll x; cin >> x;
		if (ans.find(x) != ans.end()) cout << "YES\n";
		else cout << "NO\n";
	}
}
