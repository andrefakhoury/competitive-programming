#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const lint MOD = 1000000001LL;

lint modpow(lint a, lint b) {
    a %= MOD;
    lint ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<lint> vec;
    for (int i = 0; i < n; i++) {
        lint x;
        cin >> x;
        vec.push_back(x);
    }

    if (n == 1) {
        cout << (vec[0] % MOD) << endl;
        return 0;
    } else if (n == 2) {
        lint a = vec[0], b = vec[1];
        a /= __gcd(a, b);
        a %= MOD;
        b %= MOD;
        cout << ((a * b) % MOD) << endl;
        return 0;
    } else if (n == 3) {
        lint a = vec[0], b = vec[1], c = vec[2];
        lint mul = 1;

        lint g1 = __gcd(__gcd(a, b), c);
        a /= g1; b /= g1; c /= g1;
        //mul = (mul * g1) % MOD;
        //mul = (mul * g1) % MOD;

        lint g2 = __gcd(a, b);
        a /= g2; b /= g2;
        //mul = (mul * g2) % MOD;

        lint g3 = __gcd(b, c);
        b /= g3; c /= g3;
        //mul = (mul * g3) % MOD;

        lint g4 = __gcd(a, c);
        a /= g4; c /= g4;
        //mul = (mul * g4) % MOD;

        a %= MOD;
        b %= MOD;
        c %= MOD;

        //cout << g1 << " " << g2 << " " << g3 << " " << g4 << "\n";

        lint ans = 1;
        ans = (ans * a) % MOD;
        ans = (ans * b) % MOD;
        ans = (ans * c) % MOD;
        ans = (ans * mul) % MOD;
        cout << ans << endl;
        return 0;
    }

    map<lint, map<int, int>> m;
    for (lint x : vec) {
        for (lint p = 2; p * p <= x; p++) {
            int cnt = 0;
            while (x % p == 0) {
                cnt++;
                m[p][cnt]++;
                x /= p;
            }
        }
        if (x > 1) {
            m[x][1]++;
        }
    }

    lint ans = 1;
    for (auto &x : m) {
        int pot = 0;
        //cout << x.first << ": ";
        for (auto &y : x.second) {
            pot += y.second == 1;
            //cout << y.first << "=" << y.second << " ";
        }
        ans = (ans * modpow(x.first, pot)) % MOD;
        //cout << "\n";
    }
    cout << ans << endl;
}