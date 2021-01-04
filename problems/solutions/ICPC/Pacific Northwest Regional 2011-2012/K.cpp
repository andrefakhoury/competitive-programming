#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

const int mod = 1000*1000*1000;
ll dp[1500][1500];
ll solve (int nodes, int height) {
    if (height == 0 and nodes == 1) return 1;
    if (height == -1 and nodes == 0) return 1;
    if (height < 0) return 0;
    if (height > nodes or nodes == 1) return 0;
    long long &ans = dp[nodes][height];
    if (ans != -1) return ans;
    ans = 0;
    for (int i = 0; i < nodes; i++) {
        ll ret = solve(i, height-2) * solve(nodes - i - 1, height-1) % mod;
        ret +=   solve(i, height-1) * solve(nodes - i - 1, height-1) % mod;
        ret +=   solve(i, height-1) * solve(nodes - i - 1, height-2) % mod;
        ans = (ans + ret) % mod;
    }
    return ans;
}
int main() {
    int n;
    memset (dp, -1, sizeof dp);
    while (scanf("%d", &n) != EOF) {
        long long ans = 0;
        for (int i = 0; i <= 30; i++)
            ans = (ans + solve(n, i)) % mod;
        printf("%09lld\n", ans);
    }
	return 0;
}
 