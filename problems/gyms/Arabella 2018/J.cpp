#include <bits/stdc++.h>

using namespace std;

using ull = uint64_t;

ull solve(ull x) {
    return x+1 - (1ull << __builtin_popcountll(x));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ull x;
        cin >> x;

        cout << solve(x) << "\n";
    }
}