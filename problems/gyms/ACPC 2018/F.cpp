#include <bits/stdc++.h>

using namespace std;

inline long double f(long double n, long double i, long double j) {
    return i*j*(n-i+1)*(n-j+1)/((n+1)*(n+1)*n*n/4.0);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("fetiera.in", "r", stdin);

    cout << setprecision(5) << fixed;

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if (n == 1) {
            int cor;
            cin >> cor;

            if (k%2 != cor) cout << 1 << "\n";
            else cout << 0 << "\n";
            
            continue;
        }

        long double ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int cor;
                cin >> cor;

                long double const p = f(n, i, j);
                long double const q = 1.0 - p;

                long double x = powl(q, k);
                
                if (cor) ans += x;

                for (int e = 1; e <= k; e++) {
                    x *= p/q;
                    x *= (long double)(k-e+1)/(long double)e;
                    if (e % 2 != cor) {
                        ans += x;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}