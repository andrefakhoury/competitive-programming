#include <bits/stdc++.h>
int main() {
	int n, k; scanf("%d%d", &n, &k); n++;
	return !printf("%s\n", (n%k)? "no" : "yes");
}