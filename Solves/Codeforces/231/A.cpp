#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int x1, x2, x3, ans = 0;
    while(n--) {
        scanf("%d%d%d", &x1, &x2, &x3);
        if (x1+x2+x3 >= 2) ans++;
    }
    printf("%d\n", ans);
    return 0;
}