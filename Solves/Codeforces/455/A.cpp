#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100005;

ll n, x, maxi = 0, memo[MAXN], qtt[MAXN];

ll solve(ll i) {
    if (memo[i] != -1) return memo[i];
    if (i > maxi) return 0;
    
    return memo[i] = max(qtt[i]*i + solve(i+2), solve(i+1));
}

int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x);
        qtt[x]++;
        maxi = max(maxi, x);
    }
    
    memset(memo, -1, sizeof memo);
    printf("%lld\n", solve(0));
    
    return 0;
}