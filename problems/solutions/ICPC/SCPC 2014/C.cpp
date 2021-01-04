#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG 1
#define ll long long

typedef pair<int, int> pii;

const int maxn = 10101;

struct Item {
    int num, cost;

    bool operator<(Item const& rhs) const {
        return num > rhs.num;
    }
};

Item v[maxn];
int pre[maxn];

int main() {
    int tt;
    cin >> tt;

    for (int t = 1; t <= tt; t++) {
        int m, n, c;
        cin >> m >> n >> c;

        for (int i = 1; i <= n; i++)
            v[i].cost = i*i%c, v[i].num = 0;

        for (int i = 1; i <= m; i++) {
            int tp;
            cin >> tp;

            v[tp].num++;
        }

        sort(v+1, v+n+1);

        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i-1] + v[i].cost;
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            ans = max(ans, v[i].num*pre[i]);
        }

        cout << "Case "<< t << ": " << ans << "\n";
    }

    return 0;
}