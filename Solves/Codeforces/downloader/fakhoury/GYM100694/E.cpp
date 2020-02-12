#include <bits/stdc++.h>
 #define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define mk make_pair
 using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 const int N = 100007;
 set<ii> cashes;
vector<int> purchases[N];
 int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
      for(int i = 1; i <= k; ++i) {
        cashes.insert(ii(0, i));
    }
     for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
         int j = cashes.begin()->se;
        cout << j << ' ';
        int m = purchases[j].size()? purchases[j].back() : x;
        m = (m + x);
        purchases[j].pb(x);
        cashes.erase(cashes.begin());
        int k = purchases[j].size();
        cashes.insert(ii(k * m, j));
    }
    cout << endl;
  }