#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 1007, NN = 4507;
ll c[NN][N];
const ll MAX = 240000000000000000ll;

ll inf = 10000000000000001;
void pre() {
    c[0][0] = 1;
    for(int i = 1; i < NN; ++i) {
        c[i][0] = 1;
        for(int j = 1; j <= min(i, N-1); ++j) {
            c[i][j] = c[i-1][j-1] + c[i-1][j];
            c[i][j] = min(c[i][j], inf);
        }
    }
}

ll choose(ll n, ll m) {
    if(n < m) return 0;
    ll aux = n, ans = 1;
    for(int i = 1; i <= m; ++i) {
        if(ans > MAX/aux) return inf;
        ans *= aux;
        aux--;
    }

    if(m == 4) return ans/24ll;
    else if(m == 3) return ans/6ll;
    else if(m == 2) return ans/2ll;
    return ans;
}

void solve(ll n, ll m) {
    if(m == 0) {
        assert(n == 0);
        return;
    }
    ll ans;
    if(m >= 5) {
        ll i;
        for(i = m-1; i < NN; ++i) {
            if(c[i][m] > n) break;
        }
        ans = i-1;
    } else {
        ans = m-1;
        ll l = m-1, r = 10000000000000000ll;
        while(l <= r) {
            ll mid = (l + r)/2;
            if(choose(mid, m) > n) {
                r = mid-1;
            } else {
                ans = mid;
                l = mid+1;
            }
        }
    }
    cout << ans << ' ';
    if(m >= 5) solve(n - c[ans][m], m-1);
    else solve(n - choose(ans, m), m-1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    pre();
    ll n, m;
    cin >> n >> m;

    solve(n, m);
}