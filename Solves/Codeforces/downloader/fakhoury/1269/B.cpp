#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 2e3 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 map<int, set<int> > pos;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n, m; cin >> n >> m;
 vector<int> a(n), b(n);
 for (int& i : a) cin >> i;
 for (int& i : b) cin >> i;
  sort(a.begin(), a.end());
 sort(b.begin(), b.end());
  set<int> A, B;
 for (int i = 0; i < n; i++) A.emplace(a[i]);
 for (int i = 0; i < n; i++) B.emplace(b[i]);
  map<int, int> fa, fb;
 map<int, set<int> > bf;
 for (int i = 0; i < n; i++) fa[a[i]]++;
 for (int i = 0; i < n; i++) fb[b[i]]++;
 for (auto p : fb) bf[p.se].emplace(p.fi);
  int a1 = *A.begin();
 set<int> xs;
 for (auto bb : bf[fa[a1]])
  xs.emplace((((bb - a1) % m) + m) % m);
  for (int i : A) {
  int f = fa[i];
   vector<int> toErase;
  for (int x : xs) 
   if (fb[(i+x)%m] != f) toErase.eb(x);
  for (int xx : toErase) xs.erase(xx);
 }
  cout << *xs.begin() << endl;
  return 0;
}