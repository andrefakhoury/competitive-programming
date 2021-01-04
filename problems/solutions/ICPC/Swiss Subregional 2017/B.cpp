#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

struct Point {
    double x, y;

    Point() {}
    Point(double a, double b) {
        x = a, y = b;
    }

    void read() {
        cin >> x >> y;
    }

    double dist(Point const& p) {
        return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
    }

    double operator^(Point const& p) const {
        return x*p.y - y*p.x;
    }

    Point operator-(Point const& p) const {
        return Point(x - p.x, y-p.y);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    Point A, B, C;
    A.read(); B.read(); C.read();

    vector<Point> close;
    vector<Point> all;

    double distAB = A.dist(B);
    double distBC = B.dist(C);
    double distCA = C.dist(A);
    
    int nA; cin >> nA;
    for (int i = 0; i < nA; i++) {
        double d; cin >> d;
        double ratio = d / distAB;

        Point p((B.x - A.x) * ratio + A.x, (B.y - A.y) * ratio + A.y);
        if (i == 0 || i == nA - 1) close.eb(p);
        all.eb(p);
    }
    
    int nB; cin >> nB;
    for (int i = 0; i < nB; i++) {
        double d; cin >> d;
        double ratio = d / distBC;

        Point p((C.x - B.x) * ratio + B.x, (C.y - B.y) * ratio + B.y);
        if (i == 0 || i == nB - 1) close.eb(p);
        all.eb(p);
    }
    
    int nC; cin >> nC;
    for (int i = 0; i < nC; i++) {
        double d; cin >> d;
        double ratio = d / distCA;

        Point p((A.x - C.x) * ratio + C.x, (A.y - C.y) * ratio + C.y);
        if (i == 0 || i == nC - 1) close.eb(p);
        all.eb(p);
    }

    int n = close.size();

    double ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                Point a = close[i], b = close[j], c = close[k];

                Point u = b - a, v = c - a;
                ans = max(ans, abs((u^v)) / 2.0);
            }
        }
    }

    cout << setprecision(10) << fixed << ans << endl;

    return 0;
}