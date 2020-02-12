#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 string s; cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
  if (s[i] == '.') cout << 0;
  else {
   if (s[i+1] == '.') cout << 1;
   else cout << 2;
   i++;
  }
 }
  cout << endl;
  return 0;
}
 