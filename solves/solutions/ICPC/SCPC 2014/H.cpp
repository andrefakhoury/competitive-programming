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

const int maxn = 1010, INF = 0x3f3f3f3f;

int v[maxn][maxn];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int tt;
    cin >> tt;

    for (int t = 1; t <= tt; t++) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (i == n-1 and j == m-1) continue;

                if (i != n-1 and j != m-1) {
                    v[i][j] += max(v[i+1][j], v[i][j+1]);
                }
                else if (i == n-1) {
                    v[i][j] += v[i][j+1];
                }
                else {
                    v[i][j] += v[i+1][j];
                }
            }
        }

        cout << "Case " << t << ": " << v[0][0] << "\n";
    }
    return 0;
}