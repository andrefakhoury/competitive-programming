#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("arch=haswell")

using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define DEBUG 1

using ll = long long;

typedef pair<int32_t, int32_t> ii;

int const maxn = 1001;
int const p1 = 4000037;
int const p2 = 4000039;

int const mod1 = 1e9 + 7;
int const mod2 = 1e9 + 9;

int const m1 = 4000000;

int n;
int v[4][maxn];
int a[maxn], b[maxn];
ii bh[maxn*maxn];
int bt[maxn];
ii ah[maxn];

void gen(int* a, int *b, int rot, int *res) {
    for (int i = 0; i < n; i++, rot++) {
        if (rot == n) rot -= n;
        res[i] = a[i] + b[rot];
    }
}

template<int base, int mod>
int hs(int* v) {
    int at = 0;
    for (int i = 0; i < n; i++) {
        at = ((ll)at*base + v[i])%mod;
    }
    return at;
}

int pw1[maxn], pw2[maxn];

void init() {
    pw1[0] = 1;
    for (int i = 1; i < maxn; i++) pw1[i] = (ll)pw1[i-1]*p1%mod1;

    pw2[0] = 1;
    for (int i = 1; i < maxn; i++) pw2[i] = (ll)pw2[i-1]*p2%mod2;
}

int tmp[maxn];

void f(int* v, ii *res) {
    int at = 0;
    for (int i = 0; i < n; i++) {
        at = ((ll)at*p1 + v[i])%mod1;
        tmp[i] = at;
    }

    res[0].ff = tmp[n-1];
    at = v[0];
    for (int i = 1; i < n; i++) {
        int x = ((ll)tmp[n-1]*pw1[i] - (ll)tmp[i-1]*pw1[n] + tmp[i-1] + (ll)mod1*mod1) % mod1;
        
        res[i].ff = x;

        // at = ((ll)at*p1 + v[i])%mod1;
    }

    at = 0;
    for (int i = 0; i < n; i++) {
        at = ((ll)at*p2 + v[i])%mod2;
        tmp[i] = at;
    }

    res[0].ss = tmp[n-1];
    at = v[0];
    for (int i = 1; i < n; i++) {
        int x = ((ll)tmp[n-1]*pw2[i] - (ll)tmp[i-1]*pw2[n] + tmp[i-1] + (ll)mod2*mod2) %mod2;
        
        res[i].ss = x;

        // at = ((ll)at*p2 + v[i])%mod2;
    }
}



decltype(1) main() {
    init();

    int32_t tt;
    scanf("%d", &tt);

    for (int32_t t = 1; t <= tt; t++) {
        scanf("%d", &n);

        ll tot = 0;
        for (int j = 0; j <4; j++) {
            for (int i = 0; i < n; i++) {
                scanf("%d", &v[j][i]);
                tot += v[j][i];
            }
        }

        if (tot % n != 0) {
            printf("Case %d: No\n", t);
            continue;
        }

        tot /= n;

        for (int i = 0; i < n; i++) {
            v[0][i] += m1;
            v[1][i] += m1;
        }

        for (int i = 0; i < n; i++) {
            v[2][i] = tot - v[2][i] + m1;
            v[3][i] = -v[3][i] + m1;
        }

        // for (int j = 0; j < n; j++) {for (int i = 0; i < n; i++) cout << b[j][i] << " "; cout << "\n";}

        for (int i = 0; i < n; i++) {
            gen(v[0], v[1], i, a);
            ah[i].ff = hs<p1, mod1>(a);
            ah[i].ss = hs<p2, mod2>(a);

            // cout << ah[i].ff << " " << ah[i].ss << "\n";
            // cout << hs<p1, mod1>(b[i]) << " " << hs<p2, mod2>(b[i]) << "\n";
        }

        for (int i = 0; i < n; i++) {
            gen(v[2], v[3], i, b);
            f(b, bh+n*i);
        }

        sort(ah, ah+n);
        // sort(bh, bh+n*n);

        bool ok =false;
        for (int i = 0; i < n*n and !ok; i++) {
            if (binary_search(ah, ah+n, bh[i])) {
                printf("Case %d: Yes\n", t);
                ok = true;
            }
        }

        if (!ok) printf("Case %d: No\n", t);
    }


    return 0;
}