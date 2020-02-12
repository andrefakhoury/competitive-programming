#include <bits/stdc++.h>
using namespace std;
 int main() {
 int n; scanf("%d", &n);
 set<int> st;
 for (int i = 1; i <= n*n; i++) st.insert(i);
  vector<vector<int>> ans(n);
 while (st.size()) {
  for (int i = 0; i < n; i++) {
   ans[i].push_back(*st.begin());
   st.erase(st.begin());
    if (st.size()) {
    auto it = st.end(); it--;
    ans[i].push_back(*it);
    st.erase(it);
   }
  }
 }
  for (int i = 0; i < n; i++) {
  sort(ans[i].begin(), ans[i].end());
  for (int j : ans[i]) printf("%d ", j);
  printf("\n");
 }
}