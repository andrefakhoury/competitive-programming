#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define MAXN 95

int game[MAXN];

int main() {
	int n, x;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &x); game[x] = 1;
	}

	int qt = 0, total = 0;
	for (int i = 1; i <= 90; i++) {
		total++;
		if (!game[i]) qt++;
		else qt = 0;

		if (qt == 15) return !printf("%d\n", total);
	}
	return !printf("%d\n", total);
}