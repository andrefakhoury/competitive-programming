#include <bits/stdc++.h>
 #define ff first
#define ss second
 using namespace std;
 using ll = long long;
using ii = pair<int, int>;
 int const maxn = 101010;
 int v[maxn];
int res[maxn];
 int main() {
 ios::sync_with_stdio(false), cin.tie(nullptr);
  int n;
 cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  int l = 1, r = n;
  for (int i = 1; i <= n; i++) {
  if (abs(v[i]-l) >= abs(v[i]-r))
   res[i] = l++;
  else
   res[i] = r--;
 }
  for (int i = 1; i <= n; i++)
  cout << res[i] << " \n"[i==n];
}