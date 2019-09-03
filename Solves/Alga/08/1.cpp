#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int p, q, r, s, t, u;

const double eps = 1e-12;

double eval(double x) {
    double ans = p * pow(exp(1.0), -x);
    ans += q * sin(x);
    ans += r * cos(x);
    ans += s * tan(x);
    ans += t * x * x;
    ans += u;
    
    return ans;
}

int main() {
    while(~scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u)) {
        double ans = -1, lo = 0, hi = 1, mi;
        int cnt = 500;

        while(cnt--) {
            mi = (lo + hi) / 2;

            double cur = eval(mi);
            if (cur+eps < 0) hi = mi;
            else lo = mi;

            if (abs(cur) < eps) ans = mi;
        }

        if (ans < 0) printf("No solution\n");
        else printf("%.4lf\n", ans);
    }
}