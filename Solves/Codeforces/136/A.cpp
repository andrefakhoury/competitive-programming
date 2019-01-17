#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
int a[MAXN], b[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);
	for (int i = 1; i <= n; i++) b[a[i]] = i;
	for (int i = 1; i <= n; i++) printf("%d ", b[i]);
	printf("\n");
}