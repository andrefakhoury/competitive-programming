#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG false
#define ll long long
typedef pair<int, int> pii;
 
const int INF = 0x3f3f3f3f;
const int MAXN = 305;
 
int xpt[MAXN][MAXN], m[MAXN][MAXN];
 
int x[MAXN * MAXN], y[MAXN * MAXN];
int X[MAXN * MAXN], Y[MAXN * MAXN];
 
int L, C;
 
void find(int n, int& a, int& b) {
    a = X[n];
    b = Y[n];
}
 
void swapCol(int a, int A) {
    for (int i = 1; i <= L; i++) {
        swap(m[i][a], m[i][A]);
        swap(y[m[i][a]], y[m[i][A]]);
    }
}
 
void swapRow(int a, int A) {
    for (int i = 1; i <= C; i++) {
        swap(m[a][i], m[A][i]);
        swap(x[m[a][i]], x[m[A][i]]);
    }
}
 
bool test() {
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= C; j++) {
            if (m[i][j] != xpt[i][j]) return false;
        }
    }
 
    return true;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
 
    cin >> L >> C;
 
    int cnt = 0;
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> m[i][j];
            x[m[i][j]] = i;
            y[m[i][j]] = j;
 
            xpt[i][j] = ++cnt;
            X[cnt] = i;
            Y[cnt] = j;
        }
    }
 
    int ans = 0;
    for (int n = 1; n <= cnt; n++) {
 
        // cout << endl << n << endl;
        // for (int i = 1; i <= L; i++) {
        //     for (int j = 1; j <= C; j++) {
        //         cout << m[i][j] << " (" << x[m[i][j]] << ", " << y[m[i][j]] << ")" << "\t";
        //     }
        //     cout << endl;
        // }
 
        if (x[n] != X[n]) {
            swapRow(x[n], X[n]);
            ans++;
        }
 
        if (y[n] != Y[n]) {
            swapCol(y[n], Y[n]);
            ans++;
        }
    }
 
    if (test()) cout << ans << endl;
    else cout << '*' << endl;
 
   return 0;
}