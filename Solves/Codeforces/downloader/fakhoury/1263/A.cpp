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
const int MAXN = 1e5 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int t; cin >> t;
 while(t--) {
  ll a, b, c; cin >> a >> b >> c;
  vector<ll> v = {a, b, c};
  sort(v.begin(), v.end());
  a = v[0], b = v[1], c = v[2];
   ll qt = min(c - b, a);
  a -= qt;
  b += qt;
   c += a/2;
  b += a - a/2;
   cout << min(c, b) << '\n';
 }
  return 0;
}