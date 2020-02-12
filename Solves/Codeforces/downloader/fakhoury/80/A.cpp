#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const ll INF = 1e10;
const int MAXN = 2e5 + 5;
 bool isPrime(int n) {
 for (int i = 2; i*i <= n; i++) {
  if (n%i == 0) return false;
 }
 return true;
}
 bool can(int n, int m) {
 for (int i = n+1; i < m; i++) {
  if (isPrime(i)) return false;
 }
  return isPrime(m);
}
 int main() {
 int n, m; scanf("%d%d", &n, &m);
 printf("%s\n", can(n, m) ? "YES" : "NO");
}