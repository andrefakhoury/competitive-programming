#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define mk make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;

struct Prod {
    ll p, w, add;

    Prod() {}

    void read() {
        cin >> p >> w >> add;
    }
};

vector<Prod> vec;

ll memo[10004][901][3];

ll solve(int i, int m, int activated, int n) {
    if (activated > 2) return -INF;
    if (m < -300) return -INF;

    if (i == n) {
        if (m >= 0) return 0;
        else return -INF;
    }

    ll& ret = memo[i][m + 300][activated];
    if (ret != -1) return ret;

    ret = -INF;
    ret = max(ret, solve(i+1, m - vec[i].w + vec[i].add, activated+1, n) + vec[i].p);
    ret = max(ret, solve(i+1, m - vec[i].w, activated, n) + vec[i].p);
    ret = max(ret, solve(i+1, m, activated, n));

    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    memset(memo, -1, sizeof memo);

    int n, m; cin >> n >> m;
    vec.resize(n);
    for (auto& p : vec) p.read();

    cout << solve(0, m, 0, n) << '\n';
}