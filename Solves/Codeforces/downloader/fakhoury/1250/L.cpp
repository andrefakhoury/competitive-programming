#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef pair<int, int> pii;
typedef long long ll;
 const int MAXN = 1e5 + 5;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int t;
 cin >> t;
  while (t--) {
  int a, b, c;
  cin >> a >> b >> c;
   int n = a+b+c;
   if (a == 0 or c == 0) {
   cout << (n+2)/3 << '\n';
  }
  else {
   // dois grupos com a
   // um grupo com c
   int ans = n;
    {
    int x = c, y = a/2, z = (a+1)/2;
     int cc = b;
     int topo = max({x, y, z});
     int k = min(topo-x, cc);
    x += k;
    cc -= k;
    k = min(topo-y, cc);
    y += k;
    cc -= k;
    k = min(topo-z, cc);
    z += k;
    cc -= k;
     // cout << x+y+z << " : \n";
     int v[3] = {x, y, z};
    sort(v, v+3);
     v[0] += (cc+2)/3;
    v[1] += (cc+1)/3;
    v[2] += cc/3;
    ans = min(ans, *max_element(v, v+3));
    // cout << v[0] << " " << v[1] << " " << v[2] << "\n";
   }
   {
    int x = c/2, y = (c+1)/2, z = a;
     int cc = b;
     int topo = max({x, y, z});
     int k = min(topo-x, cc);
    x += k;
    cc -= k;
    k = min(topo-y, cc);
    y += k;
    cc -= k;
    k = min(topo-z, cc);
    z += k;
    cc -= k;
     int v[3] = {x, y, z};
    sort(v, v+3);
     v[0] += (cc+2)/3;
    v[1] += (cc+1)/3;
    v[2] += cc/3;
     // cout << v[0] << " " << v[1] << " " << v[2] << "\n";
    ans = min(ans, *max_element(v, v+3));
   }
    cout << ans << "\n";
  }
 }
 return 0;
}