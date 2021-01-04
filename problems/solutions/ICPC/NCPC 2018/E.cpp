#include <bits/stdc++.h>

#pragma GCC optimize("O2","unroll-loops","strict-aliasing")

using namespace std;

using ll = long long;
using ii = pair<int, int>;

using Ve = array<int8_t, 5>;

array<Ve, 462> table;

void init() {
    vector<Ve> t;
    for (char i = 0; i <= 6; i++) {
        for (char j = 0; j <= 6; j++) {
            for (char k = 0; k <= 6; k++) {
                for (char l = 0; l <= 6; l++) {
                    for (char m = 0; m <= 6; m++) {
                        auto x = Ve{i, j, k, l, m};
                        sort(x.begin(), x.end());
                        t.push_back(x);
                    }
                }
            }
        }
    }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    for (int i = 0; i < 462; i++) table[i] = t[i];
}

inline int get_index(Ve const& v) {
    int x = lower_bound(table.begin(), table.end(), v) - table.begin();
    return x;
}

inline bool zero(Ve const& v) {
    for (auto i : v) if (i != 0) return false;
    return true;
}

inline int count_non_zero(Ve const& v) {
    int cnt = 0;
    for (auto i : v) if (i != 0) cnt++;
    return cnt;
}

double dp[462][462];

double solve(Ve amigo, Ve enemy, int t) {
    if (zero(enemy)) return 1.0;
    if (t == 0) return 0.0;

    sort(amigo.begin(), amigo.end());
    sort(enemy.begin(), enemy.end());
    double& d = dp[get_index(amigo)][get_index(enemy)];

    if (d != -1.0) return d;

    int num_choices = count_non_zero(amigo) + count_non_zero(enemy);

    d = 0.0;
    for (int i = 0; i < 5; i++) {
        if (amigo[i] == 0) continue;
        amigo[i]--;
        d += solve(amigo, enemy, t-1);
        amigo[i]++;
    }

    for (int i = 0; i < 5; i++) {
        if (enemy[i] == 0) continue;
        enemy[i]--;
        d += solve(amigo, enemy, t-1);
        enemy[i]++;
    }

    d /= (double)num_choices;
    return d;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    init();

    for (int i = 0; i < 462; i++) {
        fill(dp[i], dp[i]+462, -1.0);
    }

    int n, m, t;
    cin >> n >> m >> t;

    Ve amigo{}, enemy{};
    for (int i = 0; i < n; i++) cin >> amigo[i], amigo[i] -= '0';
    for (int i = 0; i < m; i++) cin >> enemy[i], enemy[i] -= '0';

    cout << setprecision(8) << fixed << solve(amigo, enemy, t) << "\n";
}