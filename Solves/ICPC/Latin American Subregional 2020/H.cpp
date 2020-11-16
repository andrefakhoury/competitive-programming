#include <bits/stdc++.h>

#define ff first
#define ss second

#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define clr(x, c) memset((x), (c), sizeof((x)))

using namespace std;

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl 


using ll = long long;
using ii = pair<int, int>;

int const inf = 0x3f3f3f3f;
ll const linf = 0x3f3f3f3f3f3f3f3f;

int const mod = 1e9 + 7;

seed_seq seq {
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(
    	chrono::high_resolution_clock::now().
    	time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) random_device{}(),
    (uint64_t) 17
};

mt19937 rd{seq};

int const maxn = 60;
int const maxl = 62;

ll dp[2][maxl][maxl];
char s[maxl];

int to_s(ll x) {
    clr(s, 0);
    auto it = s;
    while (x) {
        *it = '0'+(x&1);
        ++it;
        x /= 2;
    }
    return it - s;
}

ll solve(int eq, int i, int r) {
    if (r == 0) return 1;
    if (r < 0) return 0;
    if (i < 0) return 0;

    ll& d = dp[eq][i][r];

    if (d != -1) return d;

    if (eq == 0) {
        d = solve(0, i-1, r-1) + solve(0, i-1, r);
    }
    else {
        if (s[i] == '1')
            d = solve(1, i-1, r-1) + solve(0, i-1, r);
        else
            d = solve(1, i-1, r);
    }
    return d;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> p(n);
    for (auto& i : p) cin >> i;
    
    ll a, b;
    cin >> b >> a;
    b--;

    sort(rall(p));

    ll abin = 0, bbin = 0;

    for (int i = 0; i < n; i++) {
        abin <<= 1;
        bbin <<= 1;
        if (a >= p[i]) abin |= 1, a -= p[i];
        if (b >= p[i]) bbin |= 1, b -= p[i];
    }

    clr(dp, -1);
    int r = to_s(abin);
    // DBG(s);
    ll aans = solve(1, r-1, k);


    clr(dp, -1);
    r = to_s(bbin);
    // DBG(s);
    ll bans = solve(1, r-1, k);

    // DBG(aans, bans);
    cout << aans-bans << '\n';
}
