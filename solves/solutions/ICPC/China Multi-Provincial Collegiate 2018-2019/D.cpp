#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    cout << setprecision(6) << fixed;

    for (int i = 1; i <= t; i++) {
        int n, m;
        cin >> n >> m;

        cout << "Case #" << i << ": " << (n==1?n:0.5) << " " << static_cast<double>(m+1)/
                                                       static_cast<double>(2*m) << "\n";
    }
}