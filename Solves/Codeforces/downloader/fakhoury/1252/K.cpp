#include <bits/stdc++.h>
 #define ff first
#define ss second
 using namespace std;
 using ll = long long;
using ii = pair<ll, ll>;
 int const mod = 1e9+7;
 struct Seg {
 struct Node {
  ll a[2], b[2];
   static Node join(Node x, Node y) {
   Node ans;
   ans.a[0] = (y.a[0]*x.a[0] + y.a[1]*x.b[0]) % mod;
   ans.a[1] = (y.a[0]*x.a[1] + y.a[1]*x.b[1]) % mod;
   ans.b[0] = (y.b[0]*x.a[0] + y.b[1]*x.b[0]) % mod;
   ans.b[1] = (y.b[0]*x.a[1] + y.b[1]*x.b[1]) % mod;
   return ans; 
  }
   ii eval(ll x, ll y) {
   return {(x*a[0] + y*a[1]) % mod,
        (x*b[0] + y*b[1]) % mod};
  }
 };
  vector<Node> tree;
 vector<int> lazy;
  void build(int no, int l, int r, string const& s) {
  if (l == r) {
   if (s[l] == 'A') {
    tree[no] = {{1, 1}, {0, 1}};
   }
   else {
    tree[no] = {{1, 0}, {1, 1}};
   }
  }
  else {
   int m = (l+r)/2;
    build(no*2+1, l, m, s);
   build(no*2+2, m+1, r, s);
    tree[no] = Node::join(tree[no*2+1], tree[no*2+2]);
  }
 }
  Seg(string const& s) : tree(s.size()*4), lazy(s.size()*4) {
  int n = s.size();
  build(0, 0, n-1, s);
 }
  void flush(int no, int l, int r) {
  if (!lazy[no]) return;
   if (l != r) { 
   lazy[no*2+1] ^= 1;
   lazy[no*2+2] ^= 1;
  }
  lazy[no] = false;
   swap(tree[no].a, tree[no].b);
  swap(tree[no].a[0], tree[no].a[1]);
  swap(tree[no].b[0], tree[no].b[1]);
 }
  void upd(int no, int l, int r, int a, int b) {
  flush(no, l, r);
   if (a <= l and r <= b) lazy[no] = true;
  else {
   int m = (l+r)/2;
    if (b <= m) upd(no*2+1, l, m, a, b);
   else if (a > m) upd(no*2+2, m+1, r, a, b);
   else {
    upd(no*2+1, l, m, a, b);
    upd(no*2+2, m+1, r, a, b);
   }
    flush(no*2+1, l, m);
   flush(no*2+2, m+1, r);
    tree[no] = Node::join(tree[no*2+1], tree[no*2+2]);
  }
 }
  Node get(int no, int l, int r, int a, int b) {
  flush(no, l, r);
   if (a <= l and r <= b) return tree[no];
  else {
   int m = (l+r)/2;
    if (b <= m) return get(no*2+1, l, m, a, b);
   else if (a > m) return get(no*2+2, m+1, r, a, b);
   else return Node::join(
       get(no*2+1, l, m, a, b),
       get(no*2+2, m+1, r, a, b)
      ); 
  }
 }
};
 int main() {
 ios::sync_with_stdio(false), cin.tie(nullptr);
  int n, q;
 cin >> n >> q;
  string s;
 cin >> s;
  Seg sg(s);
  while (q--) {
  int op;
  cin >> op;
   if (op == 1) {
   int l, r;
   cin >> l >> r;
    sg.upd(0, 0, n-1, l-1, r-1);
  }
  else {
   int l, r;
   ll a, b;
   cin >> l >> r >> a >> b;
    auto ans = sg.get(0, 0, n-1, l-1, r-1).eval(a, b);
    cout << ans.ff << " " << ans.ss << "\n";
  }
 }
}