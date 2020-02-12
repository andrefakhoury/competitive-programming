#include <bits/stdc++.h>
using namespace std;
 const int MAXN = 2e5 + 5;
 char s[MAXN], t[MAXN];
int cnt1[26], cnt2[26];
 int main() {
 int T; scanf("%d", &T);
 while(T--) {
  memset(cnt1, 0, sizeof cnt1);
  memset(cnt2, 0, sizeof cnt2);
   int n; scanf("%d %s %s", &n, s+1, t+1);
   int q1 = 0, q2 = 0;
  for (int i = 1; i <= n; i++) {
   for (int c = s[i]-'a'+1; c < 26; c++) q1 += cnt1[c];
   for (int c = t[i]-'a'+1; c < 26; c++) q2 += cnt2[c];
    cnt1[s[i]-'a']++;
   cnt2[t[i]-'a']++;
  }
   bool ok = true;
  for (int i = 0; i < 26; i++) ok &= cnt1[i] == cnt2[i];
   if (!ok) printf("NO\n");
  else {
   ok = false;
   for (int i = 0; i < 26; i++) ok |= cnt1[i] > 1 || cnt2[i] > 1;
       if (ok || q1%2 == q2%2) printf("YES\n");
   else printf("NO\n");
  }
 }
}