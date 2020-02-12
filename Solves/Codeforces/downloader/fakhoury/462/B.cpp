#include <bits/stdc++.h>
using namespace std;
 const int MAXN = 1e5 + 5;
 char s[MAXN];
int freq[26];
int main() {
 int n, k; scanf("%d%d %s", &n, &k, s);
 for (int i = 0; i < n; i++) freq[s[i]-'A']++;
  sort(freq, freq+26, greater<int>());
  long long ans = 0;
 for (int i = 0; k && i < 26; i++) {
  long long c = min(k, freq[i]);
  k -= c;
  ans += c * c;
 }
  printf("%lld\n", ans);
}