#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define endl "\n"
#define MAX
 typedef pair<int, int> pii;
const int MAXN = 1e5 + 5;
 int bt[MAXN];
 int query(int i) {
    i++;
     int ret = INF;
    while(i > 0) {
        ret = min(bt[i], ret);
        i -= i&-i;
    }
     return ret;
}
 void update(int i, int x) {
    i++;
     while(i < MAXN) {
        bt[i] = min(x, bt[i]);
        i += i&-i;
    }
}
 struct Item {
    int a, b, c;
     bool operator<(Item const& it) const {
        return a < it.a;
    }
};
 int main() { 
 fastcin;
     int T; cin >> T;
    while(T--) {
        memset(bt, INF, sizeof bt);
         int n; cin >> n;
        int ans = 0;
         vector<Item> v(n);
        for (Item& x : v) {
            cin >> x.a >> x.b >> x.c;
        }
         sort(v.begin(), v.end());
         for (Item i : v) {
            int q1 = query(i.b-1);
            if (q1 >= i.c) ans++;
            update(i.b, i.c);
        }       
         cout << ans << '\n';
    }
}