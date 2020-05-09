#include <bits/stdc++.h>

using namespace std;

int const maxn = 303;

inline double f(double n, double i, double j) {
    return i*j*(n-i+1)*(n-j+1)/((n+1)*(n+1)*n*n/4.0);
}

double bi[maxn][maxn];

void init() {
    bi[0][0] = 1;
    for (int i = 1; i < maxn; i++) {
        bi[i][0] = 1;
        for (int j = 1; j <=i; j++) {
            bi[i][j] = bi[i-1][j-1] + bi[i-1][j];
        }
    }

    // for (int i = 0; i <= 10; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << bi[i][j] << " ";

    //     }
    //     cout << "\n";
    // }
}

inline double bin(int n, int k, double p, double q) {
    return bi[n][k]*pow(p, k)*pow(q, n-k);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("fetiera.in", "r", stdin);

    cout << setprecision(5) << fixed;

    init();

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        double ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int cor;
                cin >> cor;

                double const p = f(n, i, j);
                double const q = 1.0 - p;

                double x = pow(q, k);
                
                if (cor) ans += x;

                for (int e = 1; e <= k; e++) {
                    x *= p/q;
                    x *= double(k-e+1)/e;
                    if (e % 2 != cor) {
                        ans += x;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}