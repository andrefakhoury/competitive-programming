#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

int main() {
	ll n, x, ans = 0; cin >> n >> x;

	for (ll i = 1; i <= n; i++) {
		if (x <= i*n)
			if (x%i == 0)
				if (x%(x/i) == 0) ans++;
	}

	cout << ans << endl;
	return 0;
}