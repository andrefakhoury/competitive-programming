#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef pair<int, int> pii;
typedef long long ll;
 const int maxn = 1e5 + 5;
 int mini[maxn], maxi[maxn];
int v[maxn], pos[maxn];
 void upd(int pos_na_fila) {
 pos[v[pos_na_fila]]++;
 pos[v[pos_na_fila+1]]--;
 mini[v[pos_na_fila]] = min(mini[v[pos_na_fila]], pos_na_fila+1);
 maxi[v[pos_na_fila]] = max(maxi[v[pos_na_fila]], pos_na_fila+1);
 mini[v[pos_na_fila+1]] = min(mini[v[pos_na_fila+1]], pos_na_fila);
 maxi[v[pos_na_fila+1]] = max(maxi[v[pos_na_fila+1]], pos_na_fila);
 swap(v[pos_na_fila], v[pos_na_fila+1]);
}
 void init() {
 iota(mini, mini+maxn, 0);
 iota(maxi, maxi+maxn, 0);
 iota(pos, pos+maxn, 0);
 iota(v, v+maxn, 0);
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  init();
  int n, m;
 cin >> n >> m;
  while (m--) {
  int x;
  cin >> x;
   if (pos[x] >= 2)
   upd(pos[x]-1);
 }
  for (int i = 1; i <= n; i++) {
  cout << mini[i] << " " << maxi[i] << "\n";
 }
  return 0;
}