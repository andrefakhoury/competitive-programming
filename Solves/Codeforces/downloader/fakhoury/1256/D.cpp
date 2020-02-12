#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define eb emplace_back
#define mk make_pair
#define pb push_back
 typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 const int MAXN = 1e5 + 5;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int q; cin >> q;
 while(q--) {
  ll n, k; cin >> n >> k;
  string s; cin >> s;
   queue<int> st;
  for (int i = 0; i < n; i++) {
   if (s[i] == '0') st.emplace(i);
  }
   for (int i = 0; i < n; i++) {
   while(st.size() && st.front() <= i) st.pop();
    if (s[i] == '1') {
    if (st.size() && st.front() - i <= k) {
     k -= st.front() - i;
     s[i] = '0';
     s[st.front()] = '1';
     st.pop();
    }
    }
   }
   cout << s << '\n';
 }
  return 0;
}