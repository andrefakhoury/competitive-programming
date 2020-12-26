#include <bits/stdc++.h>
using namespace std;

int ac;

inline void solve_() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) printf("%d ", i);
    ac = n * n;
    printf("%d\n", ac);
    printf("%d\n", n);
}

int main() {
    solve_();
}
