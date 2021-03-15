#include <bits/stdc++.h>

#define pb push_back
#define fi first

using namespace std;
typedef long long ll;

const int N = 1000007;

int h[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, t; cin >> n >> t;

    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    ll start = 0;
    for(int i = 1; i <= n; ++i) {
        ll aux = t - start;

        ll ans;
        if(aux <= 0) ans = 1;
        else if(i == 0 or h[i] >= h[i-1]) {
            ans = aux/h[i] + 1;
        } else {
            ans = aux/h[i-1] + 1;

            if(aux%h[i-1] >= h[i]) ans++;
        }

        cout << ans << '\n';
        start += h[i];
        if(h[i] < h[i-1]) h[i] = h[i-1];
    }
}