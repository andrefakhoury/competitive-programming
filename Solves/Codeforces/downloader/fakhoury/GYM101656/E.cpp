#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define ll long long
 typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 int stt[101][23];
int qtt[101];
 int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
     int T; cin >> T;
    while(T--) {
        memset(stt, 0, sizeof stt);
         int n, m; cin >> n >> m;
        vector<vector<int> > a(m, vector<int>(3));
         vector<vector<pair<int, bool> > > pbit(n);
         bool ERR_ZERO = false;
        bool ERR_MORE = false;
        bool ERR_REPT = false;
        bool ERR_INVA = true;
          for (int i = 0; i < m; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
                 int x = a[i][j] < 0 ? -a[i][j] : a[i][j];
                if (x == 0) ERR_ZERO = true;
                if (x > n) ERR_MORE = true;
                if (stt[i][x]) ERR_REPT = true;
                if (ERR_ZERO || ERR_MORE || ERR_REPT) continue;
                                pbit[x-1].eb(i, a[i][j] < 0 ? 0 : 1);
                stt[i][x] = a[i][j] < 0 ? -1 : 1;
            }
             int x; cin >> x;
        }
         if (ERR_ZERO || ERR_MORE || ERR_REPT) goto PRINT;
         for (int i = 0; i < (1 << n); i++) {
            memset(qtt, 0, sizeof qtt);
            bool ok = true;
             for (int b = 0; b < n && ok; b++) {
                bool exp = i & (1 << b);
                 for (auto x : pbit[b]) {
                    if (x.se != exp) {
                        qtt[x.fi]++;
                        if (qtt[x.fi] == 3) ok = false; 
                    }
                }
             }
             if (ok) {
                ERR_INVA = false;
                break;
            }
        }
          PRINT:
        if (ERR_ZERO) cout << "INVALID: NULL RING\n";
        else if (ERR_MORE) cout << "INVALID: RING MISSING\n";
        else if (ERR_REPT) cout << "INVALID: RUNE CONTAINS A REPEATED RING\n";
        else if (ERR_INVA) cout << "RUNES UNSATISFIABLE! TRY ANOTHER GATE!\n";
        else cout << "RUNES SATISFIED!\n";
    }
     return 0;
}