#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        long long sum = 0;

        while(n--) {
            int x; cin >> x;
            sum += x%m == 0 ? 0 : (m - x%m);
        }

        cout << sum << '\n';
    }
}