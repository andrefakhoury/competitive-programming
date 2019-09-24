#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++) {
        int a, b; scanf("%d%d", &a, &b);

        long long ans = 0;
        for (int i = a + (a%2 == 0); i <= b; i += 2) {
            ans += i;
        }

        printf("Caso %d: %lld\n", cs, ans);
    }   
}