#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
const int MAXK = 12;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int a[MAXN];
ll memo[MAXN][MAXK];
 struct BIT {
 ll bt[MAXN];
  inline void add(int i, ll x) {
  i++;
  while(i < MAXN) {
   bt[i] += x;
   i += i&-i;
  }
 }
  inline ll get(int i) {
  i++;
  ll ans = 0;
  while(i) {
   ans += bt[i];
   i -= i&-i;
  }
  return ans;
 }
 } bt[MAXK];
 inline ll solve(int n, int t) {
 for (int i = 1; i <= n; i++) {
  memo[a[i]][1]++;
  bt[1].add(a[i], 1);
   for (int j = 2; j <= t; j++) {
   memo[a[i]][j] += bt[j-1].get(a[i]-1);
   bt[j].add(a[i], memo[a[i]][j]);
  }
 }
  return bt[t].get(n);
}
 int main() {
 int n, k; scanf("%d%d", &n, &k);
 for (int i = 1; i <= n; i++) scanf("%d", a+i);
 printf("%lld\n", solve(n, k+1));
 return 0;
}