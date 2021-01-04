#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAXN = 2e4 + 5;
 
struct Point {
    int x, y;
 
    Point() {}
    Point(int a, int b) {
        x = a, y = b;
    }
 
    bool operator<(Point& p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
 
    void read() {
        cin >> x >> y;
    }
};
 
struct Test {
    vector<int> y;
 
    Test() {
        y.resize(MAXN);
        fill(y.begin(), y.end(), 0);
    }
 
    void update(int l, int r, int x) {
        for (int i = l; i <= r; i++) y[i] = x;
    }
 
    bool possible(int l, int r) {
        if (!y[l] || !y[r] || y[l] != y[r]) return false;
 
        for (int i = l + 1; i <= r - 1; i++) if (y[i] && y[i] >= y[l]) return false;
        return true;
    }
};
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
 
    int n; cin >> n;
    vector<Point> pts(n);
    for (Point& p : pts) p.read();
 
    map<int, vector<int> > X;
    set<int> coords;
    map<int, int> comp;
    int cur = 0;
 
    for (Point& p : pts) coords.insert(p.x), coords.insert(p.y);
    for (int x : coords) {
        comp[x] = ++cur;
    }
    sort(pts.begin(), pts.end());
    for (Point& p : pts) {
        p.x = comp[p.x];
        p.y = comp[p.y];
    }
 
    for (Point& p : pts) X[p.x].push_back(p.y);
 
    ll ans = 0;
 
    Test seg;
    for (auto p : X) {
        vector<int> Y = p.se;
        int x = p.first;
 
        for (int i = 0; i < (int)Y.size()-1; i++) {
            ans += seg.possible(Y[i], Y[i+1]);
        }
 
        for (int y : Y) {
            seg.update(y, y, x);
        }
    }
 
    cout << ans << endl;
 
    return 0;
}