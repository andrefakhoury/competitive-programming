#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

seed_seq seq {
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(
    	chrono::high_resolution_clock::now().
    	time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) random_device{}(),
    (uint64_t) 17
};

mt19937 rd{seq};

double const pi = acos(-1);

double n, m;
double r;

double dist(double m1, double m2, double r2) {
    return r2*pi*abs(m2/m - m1/m);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> m >> n >> r;

    double a, r1, b, r2;
    cin >> a >> r1 >> b >> r2;

    double ans = 1e18;
    for (double i = 0; i <= n; i++) {
        double d = abs(r*(r1-i)/n);
        d += abs(r*(r2-i)/n);

        d += dist(a, b, r*i/n);

        ans = min(ans, d);
    }

    cout << setprecision(9) << fixed;
    cout << ans << "\n";
}
