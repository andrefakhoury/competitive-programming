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
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n; cin >> n;
  vector<int> a(n+1);
 set<int> st;
  for (int i = 1; i <= n; i++) st.emplace(i);
 for (int i = 1; i <= n; i++) cin >> a[i];
 for (int i = 1; i <= n; i++) st.erase(a[i]);
  set<int> bt;
 for (int x : st) if (a[x] == 0) bt.emplace(x);
 for (int x : bt) {
  int y = *st.begin();
  if (y == x) y = *st.rbegin();
   st.erase(y);
  a[x] = y;
 }
  for (int i = 1; i <= n; i++) {
  if (a[i] != 0) continue;
  int x = *st.begin();
  if (x == i) x = *st.rbegin();
   st.erase(x);
  a[i] = x;
 }
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
 cout << '\n';
  return 0;
}