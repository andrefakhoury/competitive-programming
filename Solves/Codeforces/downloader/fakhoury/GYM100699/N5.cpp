#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 typedef pair<int, int> pii;
typedef long long ll;
 const int MAXN = 1005;
 int memo[4][11][11][11];
 ll solve(int cur, int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0) return 0;
     int& ret = memo[cur][a][b][c];
    if (~ret) return ret;
     if (!a && !b && !c) return ret = 1;
     if (cur == 1) {
        return ret = solve(2, a, b - 1, c) + solve(3, a, b, c - 1);
    } else if (cur == 2) {
        return ret = solve(1, a - 1, b, c) + solve(3, a, b, c - 1);
    } else {
        return ret = solve(1, a - 1, b, c) + solve(2, a, b - 1, c);
    }
}
 int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
        int n; cin >> n;
    memset(memo, -1, sizeof memo);
     cout << (3 * solve(1, n, n, n)) / 2 << endl;
    return 0;
}