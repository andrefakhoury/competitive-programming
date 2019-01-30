#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int pos[MAXN];

bool isValid(int x) {
	return x >= 0;
}

void pre(int k, int l) {
	memset(pos, -1, sizeof pos);
	
	pos[0] = 0;
	for (int i = 1; i <= 1000000; i++) {
		if (isValid(i - 1) && pos[i-1] == 0) pos[i] = 1;
		else if (isValid(i - k) && pos[i-k] == 0) pos[i] = 1;
		else if (isValid(i - l) && pos[i-l] == 0) pos[i] = 1;
		else pos[i] = 0;
	}
}

int main() {
	int k, l, m; scanf("%d%d%d", &k, &l, &m);
	
	pre(k, l);
	
	while(m--) {
		int n; scanf("%d", &n);
		printf("%c", pos[n] ? 'A' : 'B');	
	}
	printf("\n");

	return 0;
}
