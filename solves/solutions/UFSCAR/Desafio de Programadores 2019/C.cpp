#include <bits/stdc++.h>
using namespace std;

const int N = 50;

int memo[N][N][N][N];

bool solve(int m, int n, int x, int y) {
    if (m == 1 && n == 1) return true;

    int& ret = memo[m][n][x][y];
    if (~ret) return ret;

    for (int i = 1; i < m; i++) {
        if (x < i && solve(i, n, x, y)) return ret = false;
        if (x >= i && solve(m-i, n, x-i, y)) return ret = false;
    }

    for (int i = 1; i < n; i++) {
        if (y < i && solve(m, i, x, y)) return ret = false;
        if (y >= i && solve(m, n-i, x, y-i)) return ret = false;
    }

    return ret = true;
}

int main() {
    memset(memo, -1, sizeof memo);
    int t; scanf("%d", &t);
    while(t--) {
        int n, m, x, y; scanf("%d%d%d%d", &n, &m, &x, &y);
        printf("%s\n", solve(n, m, x, y) == 0 ? "Vinicius" : "Bianca");
    }
}