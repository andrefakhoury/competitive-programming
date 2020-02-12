#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define mp make_pair
 typedef pair<int, int> pii;
typedef long long ll;
 inline int inv(int a, int m) {
 a %= m;
 int b = m - 2;
  int res = 1;
 while (b > 0) {
  if (b & 1) res = (ll(res) * a) % m;
  a = (ll(a) * a) % m;
  b >>= 1;
 }
  return res;
}
 const int MAXN = 2e6 + 5;
const int M[2] = {1000000007, 1000000009};
const int p[2] = {163, 167};
const int q[2] = {inv(p[0], M[0]), inv(p[1], M[1])};
int curPow[2][MAXN];
 inline void solve(string& a, string& b) {
 int n = min(a.size(), b.size());
  pii hashA(0, 0);
 for (int d = 0, i = a.size() - n; i < (int)a.size(); i++, d++) {
  char c = a[i];
  hashA.fi = (hashA.fi + (ll(curPow[0][d]) * c) % M[0]) % M[0];
  hashA.se = (hashA.se + (ll(curPow[1][d]) * c) % M[1]) % M[1];
 }
  vector<pii> hashB(b.size());
 hashB[0] = {b[0], b[0]};
 for (int i = 1; i < (int)b.size(); i++) {
  char c = b[i];
  hashB[i].fi = (hashB[i-1].fi + (ll(curPow[0][i]) * c) % M[0]) % M[0];
  hashB[i].se = (hashB[i-1].se + (ll(curPow[1][i]) * c) % M[1]) % M[1];
 }
  for (int i = a.size() - n; i < (int) a.size(); i++) {
  int tam = a.size() - i;
   if (hashA == hashB[tam-1]) {
   a += b.substr(tam);
   return;
  }
   hashA.fi = ((hashA.fi - a[i]) % M[0] + M[0]) % M[0];
  hashA.se = ((hashA.se - a[i]) % M[1] + M[1]) % M[1];
   hashA.fi = (ll(hashA.fi) * q[0]) % M[0];
  hashA.se = (ll(hashA.se) * q[1]) % M[1];
 }
  a += b;
}
 char aux[MAXN];
int main () {
 curPow[0][0] = curPow[1][0] = 1;
 for (int i = 1; i < MAXN; i++) {
  for (int j = 0; j < 2; j++) {
   curPow[j][i] = (ll(curPow[j][i-1]) * p[j]) % M[j];
  }
 }
  int k; scanf("%d %s", &k, aux);
 string s(aux);
  for (int xx = 1; xx < k; xx++) {
  scanf(" %s", aux);
  string b(aux);
  solve(s, b);
 }
  printf("%s\n", s.c_str());
 return 0;
}