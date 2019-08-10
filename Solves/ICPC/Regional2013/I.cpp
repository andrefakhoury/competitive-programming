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
const int MAXN = 1e3 + 5;
 
int memo[MAXN], n, c, t1, t2;
int a[MAXN];
 
int solve(int i) {
    if (i > n) return 0;
 
    int& ret = memo[i];
    if (~ret) return ret;
 
    int i1 = upper_bound(a+1, a+n+1, a[i] + t1) - a;
    int i2 = upper_bound(a+1, a+n+1, a[i] + t2) - a;
 
    return ret = min(t1 + solve(i1), t2 + solve(i2));
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
 
    cin >> n >> c >> t1 >> t2;
    memset(memo, -1, sizeof memo);
 
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    cout << solve(1) << endl;
 
   return 0;
}