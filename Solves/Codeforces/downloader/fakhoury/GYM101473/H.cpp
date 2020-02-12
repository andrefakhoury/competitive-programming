#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
typedef vector<vector<ll> > matrix;
 const ll MOD = 1e6;
const int K = 2;
 matrix mul(matrix A, matrix B) {
 matrix C(K+1, vector<ll>(K+1));
  for (int i = 1; i <= K; i++)
  for (int j = 1; j <= K; j++)
   for (int k = 1; k <= K; k++)
    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
  return C;
}
 matrix pow(matrix A, ll p) {
 if (p == 1) return A;
 if (p%2) return mul(A, pow(A, p-1));
  matrix X = pow(A, p/2);
 return mul(X, X);
}
 int solve(ll n, ll a, ll b) {
 a %= MOD; b %= MOD;
  vector<ll> F1(K + 1);
 F1[1] = a;
 F1[2] = (a * a + b) % MOD;
  matrix T(K+1, vector<ll>(K+1));
 T[1][1] = 0; T[1][2] = 1;
 T[2][1] = b; T[2][2] = a;
  if (n == 1) return F1[1];
 if (n == 2) return F1[2];
  T = pow(T, n-1);
  ll ans = 0;
 for (int i = 1; i <= K; i++) ans = (ans + T[1][i] * F1[i]) % MOD;
  return ans;
}
 int main() {
 ll n, a, b; scanf("%lld%lld%lld", &n, &a, &b);
 printf("%06d\n", solve(n/5ll, a, b));
  return 0;
}