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
 vector<pii> edges;
int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n; cin >> n;
 vector<int> a(n);
  set<int> st;
 for (int i = 1; i <= n; i++) st.emplace(i);
  for (int i = 0; i < n-1; i++) cin >> a[i];
  st.erase(a[0]);
 for (int i = 1; i < n; i++) {
  if (st.count(a[i])) { // eu ainda nao usei ele
   edges.eb(a[i-1], a[i]);
   st.erase(a[i]);
  } else {
   edges.eb(a[i-1], *st.rbegin());
   st.erase(*st.rbegin());
  }
 }
  cout << a[0] << '\n';
 for (pii p : edges) cout << p.fi << ' ' << p.se << '\n';
  return 0;
}