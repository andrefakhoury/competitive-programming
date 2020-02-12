#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int M = 1000000009;
const int N = 307;
typedef long long ll;
using ii = pair<int, int>;

int n, k;

ll memo[N][N][2];

ll solve(int p, int a, int ok) {
    if(p == n) return a == 0 and ok == 1;
    ll & st = memo[p][a][ok];

    if(st == -1) {
        // abrindo
        st = solve(p+1, a, ok);
        if(a < k) st += solve(p+1, a+1, ok or (a + 1 == k));
        st %= M;
        // fechando
        if(a > 0) st += solve(p+1, a-1, ok);
        st %= M;
    }
    return st;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> k;

    memset(memo, -1, sizeof memo);
    cout << solve(0, 0, k == 0) << endl;
}