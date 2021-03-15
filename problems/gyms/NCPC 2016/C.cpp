#include <bits/stdc++.h>

#define ff first
#define ss second

#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define clr(x, c) memset((x), (c), sizeof((x)))

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int const inf = 0x3f3f3f3f;
ll const linf = 0x3f3f3f3f3f3f3f3f;

int const mod = 1e9 + 7;

int from_str(string s) {
    static map<char, int> card = {
        {'2', 0},
        {'3', 1},
        {'4', 2},
        {'5', 3},
        {'6', 4},
        {'7', 5},
        {'8', 6},
        {'9', 7},
        {'T', 8},
        {'J', 9},
        {'Q', 10},
        {'K', 11},
        {'A', 12},
    };

    static map<char, int> suit = {
        {'s', 0},
        {'h', 1},
        {'d', 2},
        {'c', 3},
    };

    return card[s[0]] + 13*suit[s[1]];
}

int lis(vector<int> const& v) {
    multiset<int> ms;
    for (auto i : v) {
        auto it = ms.lower_bound(i);

        if (it != ms.end()) ms.erase(it);

        ms.insert(i);
    }

    return ms.size();
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        v.pb(from_str(s));
    }

    vector<int> g(4);
    iota(all(g), 0);

    int ans = n;

    do {
        for (int i = 0; i < (1<<4); i++) {
            auto fin = v;

            sort(all(fin),
                 [&] (int a, int b) {
                     if (g[a/13] != g[b/13]) return g[a/13] < g[b/13];
                     else if (i & (1<<(a/13))) return a < b;
                     else return a > b;
            });

            vector<int> to_check;
            for (int j : fin) {
                to_check.pb(find(all(v), j) - v.begin());
            }

            ans = min(ans, n - lis(to_check));
        }
    } while (next_permutation(all(g)));

    cout << ans << '\n';
}
