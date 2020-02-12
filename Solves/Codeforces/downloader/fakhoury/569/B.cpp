#include <bits/stdc++.h>
using namespace std;
 const int MAXN = 1e5 + 5;
 int a[MAXN];
bool used[MAXN];
 int main() {
 int n; scanf("%d", &n);
 for (int i = 1; i <= n; i++) scanf("%d", a+i);
  set<int> st;
 for (int i = 1; i <= n; i++) st.emplace(i);
 for (int i = 1; i <= n; i++) st.erase(a[i]);
  for (int i = 1; i <= n; i++) {
  int x = a[i];
  if (used[x] || x > n) x = *st.begin();
   st.erase(x);
  used[x] = true;
  printf("%d ", x);
 }
 printf("\n");
}