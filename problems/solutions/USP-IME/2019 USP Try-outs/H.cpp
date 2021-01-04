#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG 1

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 105, INF = 0x3f3f3f3f;

int nota[MAXN][MAXN];
double edge[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    memset(nota, -1, sizeof nota);

    for (int i = 1; i <= n; i++) {
        int q; cin >> q;
        while(q--) {
            int c, g; cin >> c >> g;
            nota[i][c] = g;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            double dist = 0;
            bool ok = 0;
            for (int c = 1; c <= m; c++) {
                if (nota[i][c] != -1 && nota[j][c] != -1) {
                    ok = 1;
                    dist += abs(nota[i][c] - nota[j][c]) * abs(nota[i][c] - nota[j][c]);
                }
            }

            dist = sqrt(dist);

            if (!ok) dist = INF;

            edge[i][j] = edge[j][i] = dist;
        }
    }

    for (int i = 1; i <= n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;

            if (u == -1 || edge[i][u] > edge[i][j]) {
                u = j;
            }
        }

        int chosen = m + 1;
        for (int c = 1; c <= m; c++) {
            if (nota[u][c] != -1 && nota[u][c] > nota[u][chosen] && nota[i][c] == -1)
                chosen = c;
        }

        if (chosen > m) cout << -1 << '\n';
        else cout << chosen << '\n';
    }

    return 0;
}