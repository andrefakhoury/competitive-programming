#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    if ((n-2)%3) return !printf("1 1 %d\n", n-2);
    if ((n-3)%3) return !printf("1 2 %d\n", n-3);
    return !printf("2 2 %d\n", n-4);
}