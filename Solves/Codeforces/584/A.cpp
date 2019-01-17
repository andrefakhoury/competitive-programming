#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t; scanf("%d%d", &n, &t);
    if (n == 1 && t == 10) return !printf("-1\n");
    
    printf("%d", t);
    for (int i = 1; i < n - (t==10); i++) printf("0");
    return !printf("\n");
}
