#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

const int N = 1000007, inf = 0x3f3f3f3f, M = 1000000007;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ii seg[N + N];
int v[N];

void update(int p, int val) {
    for(seg[p += N] = ii(val, p); p > 1; p >>= 1) {
        seg[p >> 1] = min(seg[p], seg[p^1]);
    }
}

ii query(int l, int r) {
    ii ans = ii(inf, inf);
    for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if(l&1) ans = min(ans, seg[l++]);
        if(r&1) ans = min(ans, seg[--r]);
    }
    return ans;
}

ll inv[N], cat[N];


ll solve(int l, int r) {
    if(l == r) return 1;
    if(r < l) return 1;

    vector<int> pos;
    int x, j;
    tie(x, j) = query(l, r + 1);
    int head = x;
    int cnt = 0;
    while(x == head) {
        cnt++;
        pos.pb(j);
        update(j, inf);
        tie(x, j) = query(l, r + 1);
    }

    pos.pb(r+1);

    ll ans = 1;
    int last = l;
    for(int p : pos) {
        ll ret = solve(last, p-1);
        ans = (ans * ret) % M;
        last = p+1;
    }

    return cat[cnt - 1] * ans % M;
}

int main() {
    memset(seg, 0x3f, sizeof seg);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    inv[1] = 1;
	for (int i=2; i<N; i++) inv[i] = M-(M/i)*inv[M%i]%M; // jeito estranho O(n) de calcular inversos

    // catalan
    cat[0] = 1;
    for(int i = 1; i + 3 < N; ++i) {
        cat[i] = (2ll * (2ll * i + 1) * cat[i-1])%M;
        cat[i] = cat[i] * inv[i + 2] % M;
    }

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        update(i, v[i]);
    }

    cout << solve(0, n-1) << endl;


}