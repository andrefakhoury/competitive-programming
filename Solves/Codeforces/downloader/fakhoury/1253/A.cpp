#include <bits/stdc++.h>
using namespace std;
 #define mk make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 1e5 + 5;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
 while(t--) {
  int n; cin >> n;
  vector<int> a(n), b(n);
   for (int& i : a) cin >> i;
  for (int& i : b) cin >> i;
   int ok = 1;
  for (int i = 0; i < n; i++) {
   if (a[i] != b[i]) {
    int at = b[i] - a[i], j;
     for (j = i; j < n; j++) {
     if (b[j] - a[j] == 0) break;
     else if (b[j] - a[j] != at) ok = 0;
    }
     for (; j < n; j++) {
     if (a[j] != b[j]) ok = 0;
    }
     break;
   }
  }
   for (int i = 0; i < n; i++) {
   if (a[i] > b[i]) ok = 0;
  }
   if (ok) cout << "YES\n";
  else cout << "NO\n";
 }
 return 0;
}