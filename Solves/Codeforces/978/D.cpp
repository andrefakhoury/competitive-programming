#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n, a[MAXN], memo[MAXN][3][3];

int solve(int i, int sum1, int sum2) {
    if (i > n) return 0;
    if (memo[i][sum1+1][sum2+1] != -1) return memo[i][sum1+1][sum2+1];
    
    if (i == 1) return memo[i][sum1+1][sum2+1] = min(1 + solve(2, 1, 0), min(1 + solve(2, -1, 0), solve(2, 0, 0)));
    if (i == 2) return memo[i][sum1+1][sum2+1] = min(1 + solve(3, 1, sum1), min(1 + solve(3, -1, sum1), solve(3, 0, sum1)));
    
    int pos1 = a[i] + 1;
    int pos2 = a[i] - 1;
    int pos3 = a[i] + 0;
    
    if ((a[i-1] + sum1) - (a[i-2] + sum2) == pos1 - (a[i-1] + sum1))
        return memo[i][sum1+1][sum2+1] = 1 + solve(i+1, 1, sum1);
    
    if ((a[i-1] + sum1) - (a[i-2] + sum2) == pos2 - (a[i-1] + sum1))
        return memo[i][sum1+1][sum2+1] = 1 + solve(i+1, -1, sum1);
    
    if ((a[i-1] + sum1) - (a[i-2] + sum2) == pos3 - (a[i-1] + sum1))
        return memo[i][sum1+1][sum2+1] = solve(i+1, 0, sum1);
    
    return memo[i][sum1+1][sum2+1] = MAXN;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    
    if (n == 1 || n == 2) return !printf("0\n");
    memset(memo, -1, sizeof(memo));
    
    printf("%d\n", solve(1, 0, 0) == MAXN ? -1 : solve(1, 0, 0));
    
    return 0;
}