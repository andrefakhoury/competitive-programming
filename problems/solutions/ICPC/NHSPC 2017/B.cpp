#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

const int N = 1000007, inf = 0x3f3f3f3f, M = 1000000007;

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int > ii;

int check(ll m, ll n, ll r, ull p) {
    int flag = 0;
    double aux = 1.0 + double(r)/100.0;
    double ans = 1;
    while(m) {
        if(m&1) {
            if(flag) return 1;
            if(ans >= 1e19/aux) return 1;
            ans = ans * aux;
        }
        
        m >>= 1;
        if(aux >= 1e19/aux) flag = 1;
        else aux *= aux;
    }
    if(ans >= 1e19/n) return 1;
    return ans * n >= p;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    for(int caso = 1; caso <= t; ++caso) {
        ll n, r; 
        ull p;
        cin >> n >> r >> p;

        ll lo = 0, hi = 123000;
        while(lo < hi) {
            ll m = (lo + hi)/2;
            if(check(m, n, r, p)) hi = m;
            else lo = m+1;
        }

        cout << "Case " << caso << ": " << lo << '\n';
    }
}