#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

using ll = long long;

double const pi = acos(-1);

double area(double n, double l, double alpha) {
    return n*l*l/4.0/tan(alpha/2.0);
}

double find_l(double n, double alpha) {
    double l = 0.0, r = 10.0;

    for (int i = 0; i < 64; i++) {
        double m = (l+r)/2.0;
        if (area(n, m, alpha) < 1.0) l = m;
        else r = m;
    }
    return l;
}

double next_l(double l, double theta) {
    return sqrt(l*l/2 * (1 - cos(theta)));
}

double solve(double n) {
    double const alpha = pi*2.0/n;
    double const theta = pi - 2.0*pi/n;

    double l = find_l(n, alpha);

    double r = 1/area(n, next_l(l, theta), alpha);


    return r/(r-1);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    freopen("baklava.in", "r", stdin);

    cout << setprecision(5) << fixed;
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout << 10000.0*solve(n) << "\n";
    }
}