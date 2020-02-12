#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
 typedef long long ll;
typedef pair<ll, ll> pii;
 struct Trie {
 int cnt, end, num;
 map<int, Trie> mp;
  Trie() {
  mp.clear();
  cnt = num = 0;
 }
  void add(int n, int i) {
  cnt++;
   if (i == -1) end++, num = n;
  else mp[(n >> i)&1].add(n, i-1);
 }
  void remove(int n, int i) {
  cnt--;
   if (i == -1) end--;
  else mp[(n >> i)&1].remove(n, i-1);
 }
  int query(int n, int i) {
  if (i == -1) return num;
  if (mp[(n >> i)&1].cnt) return mp[(n >> i)&1].query(n, i-1);
  return mp[!((n >> i)&1)].query(n, i-1);
 }
};
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int q; cin >> q;
 Trie T;
  T.add(0, 31);
  while(q--) {
  char op; cin >> op;
  int n; cin >> n;
   if (op == '+') T.add(n, 31);
  else if (op == '-') T.remove(n, 31);
  else cout << (n ^ T.query(~n, 31)) << '\n';
 }
}