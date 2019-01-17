#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, n; scanf("%d%d%d%d", &a, &b, &c, &n);
    if  (c <= a && c <= b && a+b-c+1 <= n) return !printf("%d\n", n-(a+b-c));
    return !printf("-1\n");
}