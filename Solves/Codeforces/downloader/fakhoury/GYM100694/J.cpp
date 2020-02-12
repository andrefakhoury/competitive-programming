#include <bits/stdc++.h>
    #define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define mk make_pair
    using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 const int N = 1000007;
 int a[N], b[N];
 int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
     for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
     for(int i = 0; i < m; ++i) {
        cin >> b[i];
    }
     vector<vector<int> > ans;
    for(int l = 0, r, j = 0; l < n; l = r) {
        r = l;
         while(b[l + j] < a[l]) j++;
        int cnt = 0;
        vector<int> vec;
        while(r < n and cnt < k and a[r] == b[j + r]) {
            r++;
            cnt++;
            vec.pb(r);
        }
         ans.pb(vec);
    }
     cout << ans.size() << endl;
    for(vector<int> & v : ans) {
        cout << v.size() << ' ';
        for(int x : v) cout << x << ' ';
        cout << '\n';
    }
 }