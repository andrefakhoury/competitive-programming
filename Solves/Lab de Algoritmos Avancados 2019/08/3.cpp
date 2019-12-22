#include <iostream>
using namespace std;;

int n, k, a[700];

bool check(int m) {
    int cur = 0, qtt = 0;
    for (int i = 1; i <= n+1; i++) {
        if (a[i] > m) return false;

        if (cur + a[i] > m) {
            qtt++;
            cur = a[i];
        } else cur += a[i];
    }

    if (cur > m) return false;
    return qtt <= k;
}

int main() {
    while(~scanf("%d%d", &n, &k)) {
        for (int i = 1; i <= n+1; i++) scanf("%d", a+i);

        int lo = 1, hi = 1e9, mi;
        while(lo < hi) {
            mi = (lo+hi)/2;

            if (check(mi)) hi = mi;
            else lo = mi+1;
        }

        printf("%d\n", hi);
    }
}