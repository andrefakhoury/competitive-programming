#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

const int N = 100007, inf = 0x3f3f3f3f;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

double f(double a, double b) {
    return sqrt(a * a + b * b);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;

    while(t--) {
        double a, b, c, x; cin >> a >> b >> c >> x;

        x /= 100;

        cout << fixed << setprecision(10) << f(a, b + 2 * c) + f(a, b) * x + f(a - x * a, 2 * c + (b - x * b)) << '\n';
    }
}