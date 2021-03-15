#include <bits/stdc++.h>

#define eb emplace_back
#define fi first
#define se second
#define mid ((l + r)/2)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

vector<ii> intervals;
int n, m; 

int memo[10007][107];
int solve(int p, int j) {
    if(j == m) return 1;
    int & st = memo[p][j];
    if(st == -1) {
        int l, r;
        tie(l, r) = intervals[j];
        int much = r - l;
        st = (p - much >= 0? solve(p - much, j+1) : 0) or (p + much < n? solve(p + much, j + 1) : 0);
    }
    return st;
}

int _solve() {

    cin >> n >> m;
    n++;

    intervals.clear();

    int last = -1;
    for(int i = 0; i < m; ++i) {
        int l, r; cin >> l >> r;
        if(l > last) {
            intervals.eb(l, r);
        } else {
            intervals[intervals.size()-1].second = r;
        }
        last = r;
    }

    m = intervals.size();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            memo[i][j] = -1;
        }
    }

    int ok = 0;
    for(int i = 0; i < n; ++i) {
        ok = ok or solve(i, 0);
    }
    return ok;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int f; cin >> f;

    int ok = 1;
    while(f--) {
        ok = ok and _solve();
    }

    cout << (ok? "possible" : "impossible") << '\n';
}