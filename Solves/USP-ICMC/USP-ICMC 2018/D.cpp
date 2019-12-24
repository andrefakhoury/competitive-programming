#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ll n; scanf("%lld", &n);
	ll x1, y1, x2, y2; scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);

	ll d = abs(x1-x2) + abs(y1-y2);
	d = d == 0 ? 2 : d;

	ll ans = (n - d + 2) / 2;
	ans = max(ans, 0ll);
	
	printf("%lld\n", ans);
}