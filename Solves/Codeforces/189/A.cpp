#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
int p[3];
long long memo[5000];

long long solve(int actual) {
	if (actual < 0) return -MAXN;
	if (actual == 0) return 0;
	if (memo[actual] != -1) return memo[actual];

	long long ret = -MAXN;
	for (int i = 0; i < 3; i++)
		ret = max(ret, solve(actual - p[i]));

	return memo[actual] = ret + 1;
}

int main() {
	memset(memo, -1, sizeof memo);
	int n; scanf("%d", &n);
	for (int i = 0; i < 3; i++) scanf("%d", p+i);
	printf("%lld\n", solve(n));
	return 0;
}
