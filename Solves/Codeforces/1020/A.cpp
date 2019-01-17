#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h, a, b, k, ta, fa, tb, fb, ans;
    scanf("%d%d%d%d%d", &n, &h, &a, &b, &k);
    while(k--) {
        scanf("%d%d%d%d", &ta, &fa, &tb, &fb);
        ans = abs(tb-ta);
        
        if (ta == tb) ans = abs(fa-fb);
        else {
            if (fa > b) {
                ans += abs(fa-b);
                fa = b;
            } else if (fa < a) {
                ans += abs(a-fa);
                fa = a;
            }
            ans += abs(fb-fa);
        }
        printf("%d\n", ans);
    }
    return 0;
}