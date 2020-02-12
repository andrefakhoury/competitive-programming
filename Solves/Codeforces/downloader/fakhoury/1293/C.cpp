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
 int mat[5][MAXN];
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n, q; cin >> n >> q;
  set<pii> st;
 while(q--) {
  int x, y; cin >> x >> y;
   if (mat[x][y]) { // vou tirar ele dos problemas
   mat[x][y] = 0;
    for (int i = y-1; i <= y+1; i++) {
    st.erase(mk(3-x, i));
    st.erase(mk(x, y));
   }
  } else {
   mat[x][y] = 1;
  }
   for (int yy = y-1; yy <= y+1; yy++) {
   for (int xx = 1; xx <= 2; xx++) {
    if (!mat[xx][yy]) continue;
    for (int i = max(1, yy-1); i <= yy+1; i++) {
      if (mat[3-xx][i]) {
      st.emplace(mk(xx, yy));
      st.emplace(mk(3-xx, i));
     }
    }
   }
  }
   cout << (st.size() ? "NO" : "YES") << '\n';
 }
}