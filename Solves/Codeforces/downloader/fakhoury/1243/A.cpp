#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define pb push_back
#define eb emplace_back
 typedef pair<int, int> pii;
typedef long long ll;
 int main() {
 int t; scanf("%d", &t);
 while(t--) {
  int n; scanf("%d", &n);
  vector<int> a(n);
  for (int& i : a) scanf("%d", &i);
  sort(a.rbegin(), a.rend());
   int ans = 0;
  for (int i = 0; i < n; i++) {
   if (a[i] >= i+1) ans = i+1;
  }
  printf("%d\n", ans);
 }
  return 0;
}