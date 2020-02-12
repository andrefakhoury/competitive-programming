#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> ii;
 const int maxn = 1e5 + 10;
int const maxk = 450;
ll const inf = 0x3f3f3f3f3f3f3f3f;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 int f(int x) {
 int l = 0, r = 1000;
 while (l+1 < r) {
  int m = (l+r)/2;
   if (m*(m+1)/2 <= x) l = m;
  else r = m;
 }
 if (l*(l+1)/2 < x) l++;
  return l;
}
 vector<int> bk[maxk];
int idx[maxk];
 void reset() {
 for (auto& t : bk) t.clear();
 memset(idx, 0, sizeof(idx));
}
 ll gcd(ll x, ll y) {
 if (y == 0) return x;
 return gcd(y, x%y);
}
 struct Frac {
 ll p, q;
  void norm() {
  ll g = gcd(p, q);
  p /= g, q /= g;
 }
  Frac(ll x, ll y) : p(x), q(y) {
  norm();
 }
  bool operator<(Frac const& rhs) const {
  return p*rhs.q < q*rhs.p;
 }
};
 int main() 
{
 ios::sync_with_stdio(false); cin.tie(NULL);
 int t;
 cin >> t;
  for (int tt = 1; tt <= t; tt++) {
  reset();
   int n;
  cin >> n;
   ll z = 0;
   for (int i = 0; i < n; i++) {
   int d, h;
   cin >> h >> d;
    int th = f(h);
   bk[th].push_back(d);
    z += th;
  }
   for (int i = 0; i < maxk; i++)
   sort(bk[i].begin(), bk[i].end(), greater<int>{});
   ll t = 0;
   ll ans = 0;
   while (n--) {
   int best = 0;
   Frac bval(0, 1);
    for (int i = 1; i < maxk; i++) {
    if (idx[i] < (int)bk[i].size()) {
           Frac cost(bk[i][idx[i]], i);
          if (bval < cost) {
      best = i;
      bval = cost;
     }
    }
   }
   ans += (t + best) * bk[best][idx[best]];
   t += best;
   idx[best]++;
  }
   cout << "Case #" << tt << ": ";
  cout << ans << "\n";
 }
   return 0;
}