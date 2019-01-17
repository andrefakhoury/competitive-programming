#include <bits/stdc++.h>
using namespace std;

// (x^y) mod MOD
long long power(long long x, long long y, long long MOD) {
    int res = 1;
    x %= MOD;

    while (y > 0) {
        if (y & 1) res = (res*x)%MOD;
        
        y = y >> 1;
        x = (x*x)%MOD;
    }

    return res % MOD;
}

int main() {
    long long x, k;
    const long long MOD = 1000000007;

    cin >> x >> k;

    if (x == 0) cout << 0 << endl;
    else cout << ((x%MOD * power(2, k+1, MOD))%MOD - power(2, k, MOD) + 1 + 4 * MOD)%MOD << endl;
}