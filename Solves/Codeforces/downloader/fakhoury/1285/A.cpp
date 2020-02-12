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
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n; cin >> n;
 string s; cin >> s;
  int l = 0, r = 0;
 for (int i = 0; i < n; i++) {
  l += s[i] == 'L';
  r += s[i] == 'R';
 }
  cout << l + r + 1 << '\n';
  return 0;
}