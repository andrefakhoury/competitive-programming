#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 int main() {
 int T; scanf("%d", &T);
 while(T--) {
  int n; scanf("%d", &n);
  vector<int> a(n);
   for (int& i : a) scanf("%d", &i);
   vector<int> freq = {1};
  int last = a[0];
   for (int i = 1; i < n; i++) {
   if (a[i] == last) freq.back()++;
   else freq.eb(1), last = a[i];
  }
   int k = freq.size();
   int G = freq[0], S = 0, B = 0, i;
  for (i = 1; S <= G && i < k; i++)
   S += freq[i];
  for (; i < k; i++) {
   if (G+S+B+freq[i] > n/2) break;
   B += freq[i];
  }
   if (G >= S || G >= B || G+S+B > n/2) {
   printf("0 0 0\n");
  } else {
   printf("%d %d %d\n", G, S, B);
  }
 }
   return 0;
}