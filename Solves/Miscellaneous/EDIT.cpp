#include <bits/stdc++.h>
using namespace std;

bool up(char c) {
	return c >= 'A' && c <= 'Z';
}

int solve(char* s) {
	int n = strlen(s);

	int ret1 = 0, ret2 = 0;
	for (int i = 0; i < n; i++) {
		if (i%2 == 0) ret1 += up(s[i]);
		if (i%2 == 0) ret2 += !up(s[i]);
		if (i%2 != 0) ret1 += !up(s[i]);
		if (i%2 != 0) ret2 += up(s[i]);
	}

	return min(ret1, ret2);
}

int main() {
	char s[1001];
	while(~scanf(" %s", s)) printf("%d\n", solve(s));
}