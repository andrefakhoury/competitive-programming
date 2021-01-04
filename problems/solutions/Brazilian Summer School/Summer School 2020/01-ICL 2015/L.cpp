#include <bits/stdc++.h>

#define int long long

#define ff first
#define ss second

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int const maxn = 101010;

int v[maxn];

ii fmax(ii a, ii b) {
    if (a.ff == b.ff) return ii{a.ff, a.ss + b.ss};
    return max(a, b);
}

ii pre[maxn], suf[maxn];

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        pre[i] = fmax(pre[i-1], ii{v[i], v[i]});
    }

    for (int i = n; i >= 1;  i--) {
        suf[i] = fmax(suf[i+1], ii{v[i], v[i]});
    }

    ii ans = pre[n];

    for (int i = 1; i < n; i++) {
        v[i+1]++;
        v[i]--;

        if (v[i] >= 0 and v[i+1] >= 0) {
            ii res = fmax(suf[i+2], pre[i-1]);

            res = fmax(res, ii{v[i+1], v[i+1]});
            res = fmax(res, ii{v[i], v[i]});

            if (res.ss < ans.ss) ans = res;
        }
        v[i+1]--;
        v[i]++;
    }

    for (int i = 1; i < n; i++) {
        v[i+1]--;
        v[i]++;

        if (v[i] >= 0 and v[i+1] >= 0) {
            ii res = fmax(suf[i+2], pre[i-1]);

            res = fmax(res, ii{v[i+1], v[i+1]});
            res = fmax(res, ii{v[i], v[i]});

            if (res.ss < ans.ss) ans = res;
        }
        v[i+1]++;
        v[i]--;
    }

    cout << ans.ss << "\n";
}