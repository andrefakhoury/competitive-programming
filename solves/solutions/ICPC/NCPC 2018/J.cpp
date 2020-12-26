#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

ll f(ll x) {
    if (x == 0) return 0;
    ll l = 0, r = 100000;
    while (r-l > 1) {
        ll m = (l+r)/2;
        if (m*(m-1)/2 <= x) l = m;
        else r = m;
    }
    if (l*(l-1)/2 != x) return -1;
    return l;
}

ll check(string const& s) {
    ll cnt = 0, n0 = 0;
    for (char c : s) {
        if (c == '1') cnt += n0;
        else n0++;
    }
    return cnt;
}

bool solve(ll x, ll b, ll c, ll y) {    
    if (x == -1 or y == -1) {
        return false;
    }

    ll n = x + y;

    if (n*(n-1)/2 != x*(x-1)/2 + b + c + y*(y-1)/2) {
        return false;
    }

    string ans;

    ll inv_count = 0;
    for (ll i = 0; i < n; i++) {
        if (y > 0 and inv_count + x <= c) {
            inv_count += x;
            y--;
            ans.push_back('1');
        }
        else {
            x--;
            ans.push_back('0');
        }
    }

    if (y != 0 or x != 0 or check(ans) != b) {
        return false;
    }

    cout << ans << "\n";
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if ((a|b|c|d) == 0) {
        cout << 1 << "\n";
        return 0;
    }
    
    bool ok = false;
    if (a == 0 and d == 0) {
        ok = solve(0, b, c, 0) or solve(1, b, c, 0) or 
             solve(0, b, c, 1) or solve(1, b, c, 1);
    }
    else if (a == 0) {
        ok = solve(0, b, c, f(d)) or solve(1, b, c, f(d));
    }
    else if (d == 0) {
        ok = solve(f(a), b, c, 0) or solve(f(a), b, c, 1);
    }
    else {
        ok = solve(f(a), b, c, f(d));
    }

    if (!ok) cout << "impossible\n";
}