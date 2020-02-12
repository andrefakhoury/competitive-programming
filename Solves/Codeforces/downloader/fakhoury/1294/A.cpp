#include <bits/stdc++.h>
using namespace std;
 int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int a, b, c, n; scanf("%d%d%d%d", &a, &b, &c, &n);
        int m = max({a, b, c});
                if (m == a) swap(a, c);
        if (m == b) swap(b, c);
         if (m-a > n) printf("NO\n");
        else {
            n -= m-a;
            if (m-b > n) printf("NO\n");
            else {
                n -= m-b;
                printf("%s\n", n%3 ? "NO" : "YES");                
            }
        }
    }
}