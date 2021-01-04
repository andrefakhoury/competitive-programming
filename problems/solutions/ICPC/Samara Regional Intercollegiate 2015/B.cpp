#include <bits/stdc++.h>
    
#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define mk make_pair
    
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
    
ll dist(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
    
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll p, n, x;
    cin >> p >> n >> x;
    
    ll ans = dist(0ll, 0ll, x/p, x%p);
    ans = min(ans, (n + 1 + p - 1)/p + dist(n/p, n%p, x/p, x%p));
    ans = min(ans, (p + x - 1)/p + abs(p * ((p + x - 1)/p) - x));

    ans = min(ans, (n + 1 + p - 1)/p + (n - x)/p + abs(n - p * ((n - x)/p) - x));
    ans = min(ans, (n + 1 + p - 1)/p + (n - x)/p + 1 + abs(max(0ll, n - p * (1 + (n - x)/p)) - x));

    cout << ans << endl;
}