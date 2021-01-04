#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fastcin ios::sync_with_stdio(false); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
const double EPS = 5e-7;

struct PT {
    double x, y;
    double vx, vy;

    PT() {}

    PT getAfter(double t) {
        PT p;

        p.x = x + t * vx;
        p.y = y + t * vy;

        return p;
    }
};

double dist(PT& a, PT& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
}

PT p1, p2;

double f(double t) {
    PT a = p1.getAfter(t);
    PT b = p2.getAfter(t);

    return dist(a, b);
}

double solve() {
    double lo, hi, m1, m2;

    lo = 0, hi = 1e9;
    int cnt = 100000;

    while (cnt--) {
        m1 = lo + (hi - lo) / 3.0;
        m2 = lo + 2.0 * (hi - lo) / 3.0;

        if (f(m1) < f(m2)) {
            hi = m2;
        } else {
            lo = m1;
        }
    }

    return hi;
}


int main(){
    fastcin;
    
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p1.vx >> p1.vy >> p2.vx >> p2.vy;

    cout << fixed << setprecision(9);
    cout << f(solve()) << endl;

    return 0;
}