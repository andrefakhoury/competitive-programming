#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 1;

int cnt[MAXN];

void pre() {
	for (int i = 2; i < MAXN; i++) {
		if (cnt[i]) continue;
		for (int j = i; j < MAXN; j += i) {
			cnt[j]++;
		}
	}
}

int main() {
	pre();

	int n;
	while(scanf("%d", &n), n) {
		printf("%d : %d\n", n, cnt[n]);
	}
}