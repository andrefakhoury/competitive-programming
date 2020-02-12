#include <bits/stdc++.h>
using namespace std;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  string t; cin >> t;
  map<string, int> mp;
 for (int i = 0; i <= 9; i++) {
  string s; cin >> s;
  mp[s] = i;
 }
  string cur;
 for (int i = 0; i < 80; i++) {
  cur += t[i];
  if (i%10 == 9) {
   cout << mp[cur];
   cur.clear();
  }
 }
  cout << '\n';
}