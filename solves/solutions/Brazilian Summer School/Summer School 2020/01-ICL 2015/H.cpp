#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int INF = 0x3f3f3f3f;
typedef pair<bool, int> pii;

void troca(int n, int& s, int& e) {
    int os = s, oe = e;
    s = n - os + 1;
    e = n - oe + 1;
}

inline bool b(int n, int s) {
    return s == 1 || s == n;
}

int solve(int n, int s, int e) {
    if (s > e) troca(n, s, e);

    if (e == s+1 && !b(n, s) && !b(n, e)) return -1;
    if (e == s + 1) return 1;
    if (e == s) return -1;

    int ans = 0;

    if (!b(n, s)) ans++, s++;
    if (!b(n, e)) ans++;

    if (!b(n, e)) {
        for (; s+3 <= e-1; s += 3, ans++);
        ans += e - s - 1;    
    } else {
        for (; s+3 <= e; s += 3, ans++);
        ans += e - s;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, s, e; cin >> n >> s >> e;
    int ans = solve(n, s, e);
    cout << ans << '\n';

}