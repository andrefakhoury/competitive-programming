#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll W = 10080;

vector<string> ans[100005];
char str[W];

int main() {
    ll l, m; scanf("%lld%lld", &l, &m);
    for (int i = 0; i < m; i++) {
        ll p, c, t, r;
        scanf(" %[^,],%lld,%lld,%lld,%lld", str, &p, &c, &t, &r);

        bool ok = true;

        long long k = lcm(W, t + r);

        ll q1 = k * W / (t + r);
        ll q2 = ((k * W) % (t + r)) / t;
        ok &= ((q1 + q2) * t * c) >= (k * l);

        if (ok) ans[p].push_back(string(str));
    }

    for (int i = 0; i < W; i++) {
        if (ans[i].size()) {
            for (string& s : ans[i]) printf("%s\n", s.c_str());
            return 0;
        }
    }

    printf("no such mower\n");
}