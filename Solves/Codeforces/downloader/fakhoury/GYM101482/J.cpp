#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int n;
 cin >> n;
  vector<string> a(n), b(n);
  for (auto& s : a) cin >> s;
 for (auto& s : b) cin >> s;
  int ans = 0;
  sort(a.begin(), a.end());
 sort(b.begin(), b.end());
  int i = 0;
 for (auto const& s : a) {
  while (i < n and b[i] < s) i++;
  if (b[i] == s) ans++, i++;
 }
  cout << ans << "\n";
  return 0;
}