#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 struct Bit {
 vector<int> t;
 int maxn;
 Bit(int n) {
  t.resize(n+10);
  maxn = n+10;
 }
  void update(int i, int v = 1) {
  i++;
   while(i < maxn) {
   t[i] += v;
   i += i&-i;
  }
 }
  int query(int i) {
  i++;
  int ret = 0;
   while(i > 0) {
   ret += t[i];
   i -= i&-i;
  }
   return ret;
 }
  int query(int l, int r) {
  return query(r) - query(l-1);
 }
  bool can(int l, int r) {
  return query(l, r) == r - l + 1 && query(r+1, maxn-5) == 0;
 }
  void clear() {
  t.clear();
 }
 };
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int t; cin >> t;
 while(t--) {
  int n; cin >> n;
  vector<int> a(n), pos(n+1);
  Bit bt(n);
   for (int i = 0; i < n; i++) {
   cin >> a[i];
   pos[a[i]] = i;
  }
    cout << 1;
  int l, r; l = r = pos[1];
  bt.update(1);
   for (int m = 2; m <= n; m++) {
   while (l > pos[m]) bt.update(a[l--]);
   while (r < pos[m]) bt.update(a[r++]);
      if (bt.can(1, m)) cout << 1;
   else cout << 0;
  }
   cout << '\n';
   bt.clear();
 }
  return 0;
}