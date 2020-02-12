#include <bits/stdc++.h>
using namespace std;
 vector<int> primes;
 bool isPrime(int n) {
 for (int i = 2; i*i <= n; i++) if (n%i == 0)
  return false;
 return true;
}
 void yes() {
 printf("prime\n");
 fflush(stdout);
 exit(0);
}
 void no() {
 printf("composite\n");
 fflush(stdout);
 exit(0);
}
 char aux[10];
bool guess(int n) {
 printf("%d\n", n);
 fflush(stdout);
 scanf(" %s", aux);
 return aux[0] == 'y';
}
 int main() {
 for (int i = 2; i <= 100; i++) if (isPrime(i))
  primes.push_back(i);
  int cnt = 0;
 for (int x : primes) {
  bool at = guess(x);
  cnt += at;
  if (cnt == 2) no();
  if (at && x*x <= 100) cnt += guess(x*x);
  if (cnt == 2) no();
  if (x >= 59) yes();
 }
  yes();
}