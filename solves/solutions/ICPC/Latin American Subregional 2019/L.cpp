#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n; scanf("%lld", &n);
	printf("%lld\n", 1ll << __builtin_popcountll(n));
}