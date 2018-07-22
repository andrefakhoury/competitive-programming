#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std;

typedef long long ll;

ll solve(ll x, ll n) {

	if (n == 0) return 1;
	ll ret = solve(x, n/2);
	ret*= ret%MOD;

	if (n%2) ret*=x%MOD;
	return ret;

	
}

int main() {
	ll x, n; scanf("%lld %lld", &x, &n);
	//return !printf("%lld\n", solve(x, n) % MOD);


	ll r = 1;
	while (n > 0) {
		if (n & 1) //(n%2)
			r = (r*x)%MOD;
		n = n >> 1; //(n/=2)
		x*=x;
	}
	return !printf("%lld\n", r%MOD);
}


/*

		Fn+1 = Fn + fn-1
| Fn   |  =  | 1 1 |^(n-1)  *  | 1 |
| Fn-1 |     | 1 0 |           | 1 |


		Fn+1 = Fn + Fn-1 + a
| Fn   |  =  | 1 1 a | * | 1 |
| Fn-1 |     | 1 0 0 |   | 1 |
| 1    |     | 1 0 1 |   | 1 |


*/