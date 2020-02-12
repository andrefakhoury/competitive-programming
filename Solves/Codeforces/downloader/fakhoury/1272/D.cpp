#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 int n, a[MAXN];
ll ans[MAXN][3][2];
 ll solve(int i, int del, bool started = false) {
 if (i > n) return 0;
  ll& ret = ans[i][del][started];
 if (~ret) return ret;
  ret = 0;
 if (del == 0) {
  if (a[i] > a[i-1] || started) 
   ret = max(ret, 1 + solve(i+1, 0));
  ret = max(ret, solve(i+1, 2));
 } else if (del == 1) {
  if (a[i] > a[i-1])  ret = max(ret, 1 + solve(i+1, 1));
 } else if (del == 2) {
  if (a[i] > a[i-2])  ret = max(ret, 1 + solve(i+1, 1));
 }
  return ret;
}
 int main() {
 scanf("%d", &n);
 for (int i = 1; i <= n; i++) scanf("%d", a+i);
  memset(ans, -1, sizeof ans);
  ll ret = 0;
 for (int i = 1; i <= n; i++) {
  ret = max(ret, solve(i, 0, 1));
 }
  printf("%lld\n", ret);
  return 0;
}