#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
typedef long long ll;
long long bt[MAXN];

void clear() {
    memset(bt, 0, sizeof bt);
}

ll query(int r) {
    ll sum = 0;
    while(r) {
        sum += bt[r];
        r -= (r&-r);
    }
    return sum;
}

ll query(int l, int r) {
    if (l == 0) return query(r);
    if (l > r) return 0;
    return query(r) - query(l-1);
}

void update(int p, int x) {
    while(p < MAXN) {
        bt[p] += x;
        p += (p&-p);
    }
}

int main() {
    int n;
    while(~scanf("%d", &n), n) {
        clear();

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            ans += query(x+1, MAXN-1);
            update(x, 1);
        }
        printf("%s\n", ((ans%2 == 1) ? "Martinho" : "Rene"));
    }
    
}