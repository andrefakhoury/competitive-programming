#include <bits/stdc++.h>
using namespace std;

vector<int> a;

bool check(long long k, int m) {
    long long cur = 0, qtt = 0;

    for (int& i : a) {
        if (i > k) return false;
        if (cur + i <= k) {
            cur += i;
        } else {
            qtt++;
            cur = i;
        }
    }

    return qtt <= m;
}

int main() {
    int n, k;
    while(~scanf("%d%d", &n, &k)) {
        a = vector<int>(n+1);
        for (int& i : a) cin >> i;

        long long lo = 0, hi = 1e14, mi;
        while(lo < hi) {
            mi = (lo + hi) / 2;

            if (check(mi, k)) hi = mi;
            else lo = mi + 1;
        }

        printf("%lld\n", hi);
    }   
}