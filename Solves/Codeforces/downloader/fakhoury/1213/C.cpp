#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair
#define DBG(x) cout << (#x) << ": " << x << endl;
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 1e5 + 5;
 set<ll> all;
vector<int> order;
 int main() {
 ios::sync_with_stdio(false); cin.tie(nullptr);
  int t; cin >> t;
 while(t--) {
  ll n, m; cin >> n >> m;
  ll num = n / m;
   if (n < m) {
   cout << 0 << '\n';
   continue;
  } else if (n == m) {
   cout << m%10 << '\n';
   continue;
  }
   all.clear();
  order.clear();
   ll last = m;
  while (last <= n && !all.count(last % 10)) {
   all.insert(last % 10);
   order.push_back(last % 10);
    if ((last > n - m)) break;
   last += m;
  }
   int k = order.size();
   ll groups = (num + k - 1) / k, ans = 0, norepet = num / k;
  ll qtd = num - norepet * k;
    for (int x : order) {
   ans += x * norepet;
   if (qtd > 0) ans += x;
   qtd--;
  }
   cout << ans << '\n';
 }
  return 0;
}