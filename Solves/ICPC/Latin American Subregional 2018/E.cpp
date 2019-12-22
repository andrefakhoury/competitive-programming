#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;

char s[MAXN], t[MAXN];

int main() {
	scanf(" %s %s", s, t);

	int n = strlen(s), m = strlen(t);

	int ans = 0;
	for (int i = 0; i <= n-m; i++) {
		int cur = 0;
		for (int j = 0; j < m; j++)
			cur += s[i+j] == t[j];
		ans += cur == 0;
	}

	printf("%d\n", ans);
}