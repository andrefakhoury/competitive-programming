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
 ll dist(ll a, ll b, ll c) {
 return abs(a-b) + abs(a-c) + abs(b-c);
}
 ll solve(ll a, ll b, ll c) {
 vector<ll> A = {a, a+1, a-1};
 vector<ll> B = {b, b+1, b-1};
 vector<ll> C = {c, c+1, c-1};
  ll ret = 1e10;
 for (ll x : A) {
  for (ll y : B) {
   for (ll z : C) {
    ret = min(ret, dist(x, y, z));
   }
  }
 }
 return ret;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int T; cin >> T;
 while(T--) {
  ll a, b, c; cin >> a >> b >> c;
  cout << solve(a, b, c) << '\n';
 }
   return 0;
}