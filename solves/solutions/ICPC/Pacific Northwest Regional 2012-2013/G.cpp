#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second

using ll = long long;

typedef pair<int, int> pii;

ll choose(ll n, ll k) {
    ll ans = 1;
    int cnt = 1;
    for (ll i = n-k+1; i <= n; i++, cnt++) {
        ans *= i;
        if (cnt <= k) ans /= cnt;
    }
    return ans;
}

ll f(ll n, ll added) { // n = 2**k
    ll ans = 0;
    for (ll i = max(3ll, added); i <= n+added; i ++) {
        if (i%3 == 0)
            ans += choose(n, i-added);
    }
    return ans;
}

ll solve(ll n, ll added = 0) {
    if (n == 0) return added > 0 and added%3 == 0;
    ll x = 64-__builtin_clzll(n);
    return f(x-1, added) + solve(n - (1ll<<(x-1)), added+1);
}

const ll inf = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    ll n;

    while (cin >> n) {
        ll ans = solve(n);
        cout << "Day " << n << ": Level = ";
        cout << ans  << "\n";
    }
    return 0;
}