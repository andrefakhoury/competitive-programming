#include <bits/stdc++.h>
using namespace std;
 
#define eb emplace_back
#define fi first
#define se second
 
typedef pair<int, int> pii;
typedef long long ll;
 
bool isPrime(ll n) {
	if (n == 1) return false;
	for (ll i = 2; i * i <= n; i++) if (n%i == 0) return false;
 
	return true;
}
 
ll toRight(ll n) {
	while(!isPrime(n)) n++;
	return n;
}
 
ll toLeft(ll n) {
	while(!isPrime(n)) {
		n--;
 
		if (n < 2) return 0;
	}
 
	return n;
}
 
vector<ll> a;
 
ll solve(ll p) {
	ll ans = 0;
	for (int i : a) ans += abs(i - p);
	return ans;
}
 
int main() {
	int n; scanf("%d", &n);
	a.resize(n);
 
	for (ll& i : a) cin >> i;
 
	sort(a.begin(), a.end());
 
	ll p, ans = LLONG_MAX;
 
	p = toLeft(a[n/2]);
	if (p) ans = min(ans, solve(p));
 
	p = toRight(a[n/2]);
	if (p) ans = min(ans, solve(p));
 
	p = toLeft(a[max(0, n/2 - 1)]);
	if (p) ans = min(ans, solve(p));
 
	p = toRight(a[max(0, n/2 - 1)]);
	if (p) ans = min(ans, solve(p));
 
	p = toLeft(a[min(n-1, n/2 + 1)]);
	if (p) ans = min(ans, solve(p));
 
	p = toRight(a[min(n-1, n/2 + 1)]);
	if (p) ans = min(ans, solve(p));
 
	printf("%lld\n", ans);	
}