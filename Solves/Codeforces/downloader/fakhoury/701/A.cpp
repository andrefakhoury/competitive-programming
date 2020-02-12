#include <bits/stdc++.h>
using namespace std;
 #define eb emplace_back
#define pb push_back
#define mk make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 1e5 + 5;
 int main() {
 int n; scanf("%d", &n);
 vector<pii> a(n);
 for (int i = 0; i < n; i++) {
  scanf("%d", &a[i].fi);
  a[i].se = i + 1;
 }
  sort(a.begin(), a.end());
  for (int i = 0; i < n/2; i++) {
  printf("%d %d\n", a[i].se, a[n-i-1].se);
 }
  return 0; 
}