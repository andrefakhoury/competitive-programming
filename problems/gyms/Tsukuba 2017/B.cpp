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

int const maxn = 16;

int n;
ii v[maxn];
int dp[1<<maxn];

ii sub(ii a, ii b) {
    return {a.ff - b.ff, a.ss - b.ss};
}

int f(int mask) {
    int tgt = __builtin_popcount(mask); 
    if (tgt == 0) return 0;
    if (tgt&1) return 0;
    
    auto normalize = [](ii a) {
		int g = __gcd(abs(a.ff), abs(a.ss));
        if (a.ff < 0) {
            a = {-a.ff, -a.ss};
        }
        else if (a.ff == 0 and a.ss < 0) {
            a = {-a.ff, -a.ss};
        }
		return ii{a.ff/g, a.ss/g};
	};

    vector<ii> v2;
    for (int i = 0; i < n; i++) {
        if ((1<<i)&mask) {
            v2.pb(v[i]);
        }
    }

    map<ii, int> cnt;
    int const m = v2.size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) continue;
            cnt[normalize(sub(v2[i], v2[j]))] += 1;
        }
    }


    for (auto it : cnt) {
        if (it.ss == tgt) {
            return (tgt/2)*(tgt/2-1)/2;
        }
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> v[i].ff >> v[i].ss;

    for (int i = 1; i < (1<<n); i++) {
        dp[i] = f(i);
        for (int j = (i-1)&i; j; j = (j-1)&i) {
            dp[i] = max(dp[i], dp[j] + dp[i^j]);
        }
    }

    cout << dp[(1<<n)-1] << '\n';
    
}
