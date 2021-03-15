#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int const maxn = 14;
int const maxs = 127;

int n, nsum;
ll nprod;
string num;

unordered_map<ll, ll> dp[maxn][maxs][3];

ll solve(int i, int sum, int eq, ll prod) {
    if (i >= n) {
        if (sum < nsum) return 1;
        if (sum == nsum and prod < nprod) return 1;
        if (sum == nsum and prod == nprod and eq == 0) return 1;
        return 0;
    }

    if (sum > nsum) return 0;
    if (sum == nsum and prod > nprod) return 0;
    if (sum == nsum and prod == nprod and eq >= 1) return 0;

    if (dp[i][sum][eq].count(prod)) {
        return dp[i][sum][eq][prod];
    }

    ll d = 0;

    for (int j = 0; j < 10; j++) {
        int new_eq;
        if (eq == 0 or eq == 2) new_eq = eq;
        else {
            if (j == num[i]-'0') new_eq = 1;
            else if (j < num[i]-'0') new_eq = 0;
            else new_eq = 2;
        }

        ll k = solve(i+1, sum + j, new_eq, prod * (1 + j));

        d += k;

        if (k == 0) break;
    }

    return dp[i][sum][eq][prod] = d;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> num;
    n = num.size();

    for (int i = 0; i < n; i++) {
        nsum += num[i]-'0';
    }

    nprod = 1;
    for (int i = 0; i < n; i++) {
        nprod *= (num[i] -'0') + 1;
    }

    ll ans = solve(0, 0, 1, 1);

    cout << ans << "\n";
}
