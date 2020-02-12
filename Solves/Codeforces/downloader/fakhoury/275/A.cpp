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
 bool s[5][5];
int g[5][5];
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) {
   cin >> g[i][j];
   g[i][j] %= 2;
 }
   for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) s[i][j] = true;
  int ord[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  for (int i = 1; i <= 3; i++) {
  for (int j = 1; j <= 3; j++) {
   if (g[i][j]) {
    s[i][j] = !s[i][j];
    for (int k = 0; k < 4; k++) {
     int I = i + ord[k][0];
     int J = j + ord[k][1];
     s[I][J] = !s[I][J];
    }
   }
  }
 }
  for (int i = 1; i <= 3; i++) {
  for (int j = 1; j <= 3; j++) cout << s[i][j];
  cout << endl;
 }
  return 0;
}
 