#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

bool test(vector<int> const& v, vector<int> num) {
    int n = v.size();
    int m = num.size();

    for (int i = 0; i+m-1 < n; i++) {
        bool ok = true;
        for (int j = i; j < i+m; j++) {
            if (v[j] != num[j-i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return true;
        }
    }
    return false;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);

    for (auto& i : v) cin >> i;

    auto to_vi = [] (int x) {
        if (x == 0) {
            return vector<int>{0};
        }
        vector<int> v;
        while (x != 0) {
            v.push_back(x%10);
            x /= 10;
        }

        reverse(v.begin(), v.end());
        return v;
    };

    for (int i = 0;; i++) {
        if (!test(v, to_vi(i))) {
            cout << i << "\n";
            return 0;
        }
    }
}
