#include <bits/stdc++.h>

using namespace std;

#define MAXN 400005

map<char, int> oc;
char str[MAXN];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf(" %c", str+i);
		oc[str[i]]++;
	}
	int cur = 'a';
	for (int i = 0; i < k; i++) {
		if (oc[cur]--) {
			str[i] = '.';
		} else {
			cur++; i--;
		}
	}

	for (int i = 0; i < n; i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			printf("%c", str[i]);
	}
	printf("\n");
}