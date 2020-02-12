#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 1e5 + 5;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
 while(t--) {
  int a, b; cin >> a >> b;
  if (__gcd(a, b) == 1) cout << "Finite\n";
  else cout << "Infinite\n";
 }
  return 0;
}