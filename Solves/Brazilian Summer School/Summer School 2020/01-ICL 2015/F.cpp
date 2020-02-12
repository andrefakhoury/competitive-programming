#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int const mod = 1e9 + 9;
int const maxp = 1300000;
char s[maxp];
vector<int> p;

void sieve() {
    for (int i = 3; i*i < maxp; i += 2) {
        if (s[i/2] == 0) {
            for (int j = i*i; j < maxp; j += i*2) s[j/2] = 1;
        }
    }
    for (int i = 3; i < maxp; i += 2) if (s[i/2] == 0) p.push_back(i);
}

vector<int> factor(int x) {
    vector<int> ans;

    int k = x;
    for (int i = 2; i*i <= x; i++) {
        while (k%i == 0) {
            k /= i;
            ans.push_back(i);
        }
    }
    if (k != 1) ans.push_back(k);

    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    return ans;
}

ll fexp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b&1) ans = ans*a%mod;
        a = a*a%mod;
        b /= 2;
    }
    return ans;
}

pair<long double, ll> calc(vector<int> v) {
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll ans = 1;
    long double x = 0;
    auto it = p.begin();
    for (int prime : v) {
        ans = ans*fexp(*it, prime-1)%mod;
        x += (long double)(prime-1) * logl(*it);
        ++it;
    }

    return {x, ans};
}

void gen_candidates(vector<vector<int>> &res, vector<int> tmp, int n, int depth = 0) {
    if (n == 1) {
        res.push_back(tmp);
        return;
    }
    if (depth == 6) return;
    vector<int> t = tmp;
    auto k = factor(n);
    for (auto i : k) t.push_back(i);

    res.push_back(t);
    int facs[] = {4, 6, 8, 9};

    for (int ps : facs) {
        if (n%ps == 0) {
            tmp.push_back(ps);
            gen_candidates(res, tmp, n/ps, depth+1);
            tmp.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    sieve();

    int n;
    cin >> n;

    auto v = factor(n);

    
    vector<vector<int>> candidates = {v};

    gen_candidates(candidates, {}, n);
    
    pair<long double, ll> ans = {1e200, 0x3f3f3f3f};
    for (auto vi : candidates) {
        ans = min(ans, calc(vi));
    }

    cout << ans.ss << "\n";
}