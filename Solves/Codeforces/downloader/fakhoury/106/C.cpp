#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const ll INF = 1e10;
const double EPS = 1e-7;
const int MAXN = 1e3 + 5;
 struct ST {
 int a, b, c, d;
  ST() {}
  void read() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
 }
};
 int n, m, c0, d0;
ll memo[11][101][1001];
ST vec[11];
 long long solve(int i, int usd, int qtt) {
 if (i > m) return (qtt/c0) * d0;
  ll& ret = memo[i][usd][qtt];
 if (~ret) return ret;
  ll r1 = 0;
 if (qtt >= vec[i].c && usd + vec[i].b <= vec[i].a)
  r1 = vec[i].d + solve(i, usd+vec[i].b, qtt-vec[i].c);
  return ret = max(solve(i+1, 0, qtt), r1);
}
 int main() {
 memset(memo, -1, sizeof memo);
 scanf("%d%d%d%d", &n, &m, &c0, &d0);
  for (int i = 1; i <= m; i++) vec[i].read();
 printf("%lld\n", solve(1, 0, n));
}