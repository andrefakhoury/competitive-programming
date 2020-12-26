#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

using namespace std;

const int MAXN = 310;
const int INF = 0x3f3f3f3f;

int n, m;
int pu[MAXN], pv[MAXN], cost[MAXN][MAXN];
int pairV[MAXN], way[MAXN], minv[MAXN];
bool used[MAXN];

void hungarian() {
    memset(&pairV, 0, sizeof pairV);
    for (int i = 1, j0 = 0; i <= n; i++) {
        pairV[0] = i;
        memset(&minv, INF, sizeof minv);
        memset(&used, false, sizeof used);
        do {
            used[j0] = true;
            int i0 = pairV[j0], delta = INF, j1;
            for (int j = 1; j <= m; j++) {
                if (used[j]) continue;
                int cur = cost[i0][j] - pu[i0] - pv[j];
                if (cur < minv[j]) minv[j] = cur, way[j] = j0;
                if (minv[j] < delta) delta = minv[j], j1 = j;
            }
            for (int j = 0; j <= m; j++) {
                if (used[j]) pu[pairV[j]] += delta, pv[j] -= delta;
                else minv[j] -= delta;
            }
            j0 = j1;
        } while(pairV[j0] != 0);
        do {
            int j1 = way[j0];
            pairV[j0] = pairV[j1];
            j0 = j1;
        } while(j0);
    }
}

int32_t main() {
    scanf("%lld", &n);
    m = n;

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        scanf("%lld", &cost[i][j]);
    
    hungarian();

    vector<ii> vec;
    ll ans = 0;
    for (int j = 1; j <= n; j++) {
        if (pairV[j] == 0) continue;
        ans += cost[pairV[j]][j];
        vec.emplace_back(pairV[j], j);
    }
    printf("%lld\n", ans);
    for (auto p : vec) printf("%lld %lld\n", p.fi, p.se);
}