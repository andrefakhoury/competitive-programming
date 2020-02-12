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
 bool L[MAXN], R[MAXN];
map<int, bool> used;
 int main() {
 int n, m; scanf("%d%d", &n, &m);
 vector<int> a(n), pos;
  for (int i = 0; i < n; i++) cin >> a[i];
 sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) used[a[i]] = true;
  set<int> all;
 for (int i = 0; i < n; i++) all.emplace(i);
  ll ans = 0;
 int delta = 0;
 while((int)pos.size() < m) {
  delta++;
  vector<int> toErase;
   for (int i : all) {
   // cout << i << ": " << a[i] << " (" << L[i] << ", " << R[i] << ")" << endl;
   if((int)pos.size() >= m) break;
      L[i] |= used[a[i] - delta];
   if (!L[i]) {
    pos.eb(a[i] - delta);
    used[a[i] - delta] = true;
    ans += delta;
   }
   if((int)pos.size() >= m) break;
    R[i] |= used[a[i] + delta];
   if (!R[i]) {
    pos.eb(a[i] + delta);
    used[a[i] + delta] = true;
    ans += delta;
   }
   if((int)pos.size() >= m) break;
    if (L[i] && R[i]) toErase.eb(i);
  }
   for (int x : toErase) all.erase(x);
 }
  cout << ans << '\n';
 for (int i = 0; i < m; i++) cout << pos[i] << ' ';
 cout << '\n';
    return 0;
}