#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int MAXN = 1005;

int n, w, a[MAXN];

void impossible() {
	exit(!printf("0\n"));
	// return !printf("0\n");
}

int main() {
	scanf("%d %d", &n, &w);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);

	int minimo = 0, atual = 0;
	for (int i = 1; i <= n; i++) {
		int mudanca = a[i] + atual;
		if (mudanca < 0) minimo -= mudanca;
		if (mudanca > w) impossible();

		if (minimo < 0 || minimo > w) impossible();
		atual = min(max(mudanca, 0), w);
	}

	int maximo = w; atual = w;
	for (int i = 1; i <= n; i++) {
		int mudanca = a[i] + atual;
		if (mudanca > w) maximo += w - mudanca;
		if (mudanca < 0) impossible();

		if (maximo < 0 || maximo > w) impossible();
		atual = min(max(mudanca, 0), w);
	}	

	printf("%d\n", max(0, maximo - minimo + 1));
}