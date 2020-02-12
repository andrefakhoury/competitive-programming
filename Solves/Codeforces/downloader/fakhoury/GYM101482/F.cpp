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
const int INF = 0x3f3f3f3f;
 mt19937 rg(17);
 int const max_tries = 1009;
 struct Point {
 int x, y;
  ll operator^(Point const& rhs) const {
  return (ll)x*rhs.y - (ll)y*rhs.x;
 }
  Point operator-(Point const& rhs) const {
  return {x-rhs.x, y-rhs.y};
 }
};
 int f(vector<Point> const& v, Point a, Point b) {
 int cnt = 0;
 for (Point const& p : v) {
  if (((p-a)^(p-b)) == 0) cnt++;
 }
 return cnt;
}
 bool brute(vector<Point> const& v, int p) {
 int n = v.size();
 for (int i = 0; i < n; i++) {
  for (int j = i+1; j < n; j++) {
   int cnt = f(v, v[i], v[j]);
    if (100*cnt >= p*n) return true;
  }
 }
 return false;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int n, p;
 cin >> n >> p;
  vector<Point> v(n);
 for (auto& p : v) cin >> p.x >> p.y;
  if (n == 1) return cout << "possible\n", 0;
  bool ans = false;
 if (n <= 300) ans = brute(v, p);
 else {
  uniform_int_distribution<int> rng(0, n-1);
  for (int t = 0; t < max_tries and !ans; t++) {
   int a = rng(rg), b = rng(rg);
    while (a == b) {
    a = rng(rg), b = rng(rg);
   }
    int cnt = f(v, v[a], v[b]);
    if (100*cnt >= p*n) ans = true;
  }
 } 
  if (ans) cout << "possible\n";
 else cout << "impossible\n";
 return 0;
}