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
const int MAXN = 3e6 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 ll f[MAXN];
int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 ll n, M; cin >> n >> M;
  f[0] = 1;
 for (ll i = 1; i < MAXN; i++) f[i] = f[i-1] * i % M;
  ll ans = 0;
 for (int i = 1; i <= n; i++) {
  ll cur = (((n - i + 1) * (n - i + 1) % M) * f[i] % M) * f[n - i] % M;
  ans = (ans + cur) % M;
 }
  cout << ans << '\n';
  return 0;
}