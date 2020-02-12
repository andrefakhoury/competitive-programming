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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 int main() {
 int n; scanf("%d", &n);
  double ans = 0;
 for (int i = 0; i < n; i++) ans += 1.0/(n-i);
 printf("%.8lf\n", ans);
  return 0;
}