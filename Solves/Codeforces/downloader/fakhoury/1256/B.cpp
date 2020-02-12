#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define eb emplace_back
#define mk make_pair
#define pb push_back
 typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 const int MAXN = 1e5 + 5;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int q; cin >> q;
 while(q--) {
  int n; cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
   vector<int> used(n, 0);
  for (int k = 1; k <= n; k++) {
   int pos = find(a.begin(), a.end(), k) - a.begin();
   for (int i = pos; i > k-1; i--) {
    if (!used[i-1] && a[i-1] > a[i]) {
     swap(a[i], a[i-1]);
     used[i-1] = 1;
    }
   }
  }
   for (int i : a) cout << i << ' ';
  cout << '\n';
 }
  return 0;
}