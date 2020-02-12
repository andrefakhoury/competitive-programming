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
const double EPS = 1e-7;
 double f(double a, double b, double c, double d, double v) {
    return a * v * v * v * v + b * v * v * v + c * v * v + d * v;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
    double a, b, c, d, m, t;
    while(cin >> a >> b >> c >> d >> m >> t) {
     double lo = 0, hi = 1e9, mi;
    while(lo+EPS < hi) {
        mi = (lo + hi) / 2.0;
        double qtt = f(a, b, c, d, mi);
        double horas = m / mi;
        double fuel = qtt * horas;
        if (fuel+EPS <= t) lo = mi;
        else hi = mi;     
    }
     cout << setprecision(2) << fixed << floor(lo*100)/100.0 << '\n';
     }
   return 0;
}
 