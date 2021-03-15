#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

bool a[366];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[x] = 1;
    }

    int ans = 0;
    vector<int> cur;
    for (int i = 1; i <= 365; i++) {
        if (a[i]) cur.push_back(i);

        int sum = 0;
        for (int x : cur) sum += i - x + 1;
        if (sum >= 20) { // precisa limpar
            ans++;
            cur.clear();
        }
    }

    if (cur.size()) ans++;

    cout << ans << '\n';
}