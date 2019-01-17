#include <bits/stdc++.h>
using namespace std;

int aoba[5];
map<int, int> old;

int main() {
	int n = 4;

	for (int i = 1; i <= n; i++) scanf("%d", aoba+i);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += old[aoba[i]];
		old[aoba[i]] = 1;
	}

	printf("%d\n", ans);
}