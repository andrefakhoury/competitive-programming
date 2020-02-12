#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll N = 1e6;

ll sum[N], a[N];

inline ll acc(int l, int r) {
    return sum[r] - sum[l-1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        ll h, m, s; cin >> h >> m >> s;
        a[i] = s + m * N + h * N * N;
        a[i+n] = 12 * N * N + a[i];
    }
    sort(a+1, a+n+n+1);

    for (int i = 1; i <= n + n; i++) {
        sum[i] = sum[i-1] + a[i];
    }

    ll ans = LLONG_MAX;
    for (int i = n+1; i <= n + n; i++) {
        ans = min(ans, n * a[i] - acc(i-n+1, i));
    }

    int s = ans % N;
    ans /= N;
    int m = ans % N;
    ans /= N;
    int h = ans;

    cout << h << ' ' << m << ' ' << s << '\n';
}