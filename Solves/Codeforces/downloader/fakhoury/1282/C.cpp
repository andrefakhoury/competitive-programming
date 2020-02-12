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
const int MAXN = 2e5 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 inline ll qtt(ll l, ll r, ll A, ll a) {
 if (l > r) return 0;
 return min((r - l)/a, A);
}
 inline void _solve() {
 ll n, T, a, b; cin >> n >> T >> a >> b;
  vector<ll> hard(n+1), tempo(n+1);
  ll A = 0, B = 0;
 for (ll i = 1; i <= n; i++) cin >> hard[i];
 for (ll i = 1; i <= n; i++) A += !hard[i], B += hard[i];
 for (ll i = 1; i <= n; i++) cin >> tempo[i];
  set<ll> ts = {0ll, T};
 map<ll, vector<ll> > stt;
 map<ll, bool> vis;
  for (ll i = 1; i <= n; i++) {
  ts.emplace(tempo[i]);
  for (int xx = 1; xx <= 2; xx++) {
   if (tempo[i]+xx <= T) ts.emplace(tempo[i]+xx);
   if (tempo[i]-xx >= 1) ts.emplace(tempo[i]-xx);
  }
   stt[tempo[i]].eb(i);
 }
  ll lkdA = 0, lkdB = 0;
 ll lftA = A, lftB = B;
 ll l = 0, ans = 0;
 while(ts.size()) {
  ll t = *ts.begin();
  ts.erase(t);
  if (t > T || vis[t]) break;
  vis[t] = true;
   for (ll x : stt[t]) {
   if (hard[x]) l += b, lftB--, lkdB++;
   else l += a, lftA--, lkdA++;
  }
   ll ra = qtt(l, t, lftA, a);
  ll rb = qtt(l+ra*a, t, lftB, b);
   if (t >= l) ans = max(ans, lkdA + lkdB + ra + rb);
  else ts.emplace(l);
 }
  cout << ans << '\n';
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int T; cin >> T;
 while(T--) _solve();
  return 0;
}