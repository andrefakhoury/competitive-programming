#include <bits/stdc++.h>

#define ff first
#define ss second

#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define clr(x, c) memset((x), (c), sizeof((x)))

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int const inf = 0x3f3f3f3f;
ll const linf = 0x3f3f3f3f3f3f3f3f;

int const mod = 1e9 + 7;

int const maxn = 101010;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ii> v(n);

    for (auto& i : v) cin >> i.ff >> i.ss;

    vector<int> p(maxn);  

    for (auto i : v) {
        p[i.ff] += 1;
        p[i.ss] -= 1;
    }

    for (int i = 1; i < maxn; i++) {
        p[i] += p[i-1];
    }

    int res2 = *max_element(all(p));

    vector<int> l(maxn), r(maxn);

    for (auto i : v) {
        l[i.ff]++;
        r[i.ss]++;
    }

    for (int i = 1; i < maxn; i++) {
        l[i] += l[i-1];
        r[i] += r[i-1];
    }

    int res1 = 0;
    for (auto i : v) {
        int cnt = l[i.ss-1] - r[i.ff];

        res1 = max(res1, cnt);
    }

    cout << res1 << ' ' << res2 << '\n';
}
