#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
 const int MAXN = 1e4 + 5;
const int INF = 0x3f3f3f3f;
 vector<int> edges1[MAXN], edges2[MAXN];
char a[MAXN], b[MAXN];
 struct HASH {
    int sz;
    ull fi, se;
     HASH() {}
    HASH(ull a, ull b) {
        sz = 1;
        fi = a, se = b;
    }
     HASH& operator+=(HASH const& b) {
        fi ^= (b.fi >> 26) + (b.fi << 13) + fi*0x123affb3141 + 0xf3f4f1fa75fb*b.fi;
        se ^= (b.se >> 51) + (b.se << 30) + se*0xdeadbeef123 + 0x12cdef1e7571*b.se;
        sz += b.sz;
        return *this;
    }
     bool operator==(HASH const& b) {
        return fi == b.fi && se == b.se && sz == b.sz;
    }
     bool operator<(HASH const& b) const {
        return tie(sz, fi, se) < tie(b.sz, b.fi, b.se);
    }
};
 vector<HASH> h1, h2;
 HASH dfs(int u, char* h, vector<HASH>& hs, vector<int>* edges) {
     HASH ans(h[u], h[u]);
     for (int v : edges[u]) {
        ans += dfs(v, h, hs, edges);        
    }
     hs.push_back(ans);
     return ans;
}
 int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
     int t; cin >> t;
    while(t--) {
        int m, n; cin >> m >> n;
         int r1 = -1, r2 = -1;
        for (int i = 0; i < m; i++) {
            cin >> a[i];
            int x; cin >> x;
            if (x == -1) r1 = i;
            if (x != -1) {
                edges1[x].push_back(i);
            }
        }
         for (int i = 0; i < n; i++) {
            cin >> b[i];
            int x; cin >> x;
            if (x == -1) r2 = i;
            if (x != -1) {
                edges2[x].push_back(i);
            }
        }
         dfs(r1, a, h1, edges1);
        dfs(r2, b, h2, edges2);
         sort(h1.begin(), h1.end());
        sort(h2.begin(), h2.end());
         int ans = 0;
        for (HASH& h : h1) {
            if (binary_search(h2.begin(), h2.end(), h)) {
                ans = max(ans, h.sz);
            }
        }
         cout << ans << '\n';
         for (int i = 0; i < m; i++) edges1[i].clear();
        for (int i = 0; i < n; i++) edges2[i].clear();
        h1.clear(); h2.clear();
    }
     return 0;
}