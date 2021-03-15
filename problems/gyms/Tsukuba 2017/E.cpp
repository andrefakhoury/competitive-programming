#include <bits/stdc++.h>

#define eb emplace_back
#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int N = 1000007;

string s, t;


ll seg[N + N];

ll query(int l, int r) {
    ll ans = 1e18;
    for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if(l&1) ans = min(ans, seg[l++]);
        if(r&1) ans = min(ans, seg[--r]);
    }
    return ans;
}

void update(int p, ll val) {
    for(seg[p += N] = val; p > 0; p >>= 1) {
        seg[p >> 1] = min(seg[p], seg[p^1]);
    }
}

ll f[N];
ll acc[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;

    cin >> s >> t;

    acc[0] = 0;
    for(int i = 1; i < n; ++i) {
        acc[i] = acc[i-1] + (t[i] != t[i-1]);
    }

    for(int i = n-1; i >= 0; --i) {
        update(i, 2 * f[i+1] + acc[i]);
        if(s[i] == t[i]) {
            f[i] = f[i+1];
        } else {
            int j = min(n-1, i + k - 1);
            f[i] = 1 + (query(i, j + 1) + 1 - (i? acc[i] : 0))/2;
        }
    }

    cout << f[0] << endl;
}