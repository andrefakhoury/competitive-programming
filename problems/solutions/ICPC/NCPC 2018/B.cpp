#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        if (s == "mumble") continue;
        int x = stoi(s);
        if (x != i) flag = false;
    }

    if (flag) cout << "makes sense\n";
    else cout << "something is fishy\n";
}