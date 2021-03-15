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

struct Dsu {
    map<int, int> pai, sz, sza, maxi;
    map<int, ll> sum;

    int find(int x) {
        if (pai.count(x) == 0) {
            pai[x] = x;
            sz[x] = 1;
            sza[x] = 0;
            maxi[x] = x;
            sum[x] = x;
            return x;
        }

        if (pai[x] == x) return x;
        return pai[x] = find(pai[x]);
    }

    void join(int x, int y) {
        x = find(x), y = find(y);

        if (x == y) {
            sza[x]++;
            return;
        }

        pai[y] = x;
        sz[x] += sz[y];
        sum[x] += sum[y];
        sza[x] += sza[y] + 1;
        maxi[x] = max(maxi[x], maxi[y]);
    }
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    Dsu dsu;

    int n;
    cin >> n;

    ll sum = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        sum += a + b;

        dsu.join(a, b);
    }

    ll s = 0;

    for (auto i : dsu.pai) {
        if (i.ff == i.ss) {
            s += dsu.sum[i.ff];
            if (dsu.sza[i.ff] != dsu.sz[i.ff]) {
                s -= dsu.maxi[i.ff];
            }
        }
    }

    cout << sum - s << '\n';
}
