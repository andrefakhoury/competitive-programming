#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, ll> pil;

int solve(ll x) {
    int ret = 0;
    while(x%3 == 0) {
        ret++;
        x/=3;
    }
    return ret;
}

int main() {
    int n; scanf("%d", &n);
    ll x;
    vector<pil> v;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        v.pb(mp(-solve(x), x));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) printf("%lld ", v[i].second);
    return 0;
}