#include <bits/stdc++.h>
using namespace std;

int main() {
	long long k, n, w; scanf("%lld%lld%lld", &k, &n, &w);
	long long total = 0;
	for (int i = 1; i <= w; i++) total += i*k;
	printf("%lld\n", (total-n > 0) ? total-n : 0);
}