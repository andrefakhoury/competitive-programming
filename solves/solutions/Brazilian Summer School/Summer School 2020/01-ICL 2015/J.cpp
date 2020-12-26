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
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<pair<ll, int> > fac(ll n) {
	vector<pair<ll, int> > ans;
	for (ll i = 2; i * i <= n; i++) {
		if (n%i == 0) {
			ans.eb(i, 0);
			while(n % i == 0) {
				n /= i;
				ans.back().se++;
			}
		}
	}

	return ans;
}

ll nck(ll n, ll k, ll m) {
	vector<pair<ll, int> > f = fac(k);



}

int main() {
	ll n, k, m; scanf("%lld%lld%lld", &n, &k, &m);
	printf("%lld\n", nck(n, k, m));
	return 0;
}