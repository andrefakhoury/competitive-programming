#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

bool solve(int n, int m) {
	map<int, int> fac;
	for (int i = 2; i*i <= m; i++) {
		while (m%i == 0) {
			m /= i;
			fac[i]++;
		}
	}

	if (m > 1) fac[m]++;

	int p, aux, qtd;

	for (auto it : fac) {
		p = it.first;
		aux = n;
		qtd = 0;
		while (aux) qtd += (aux/=p);
		if (qtd < it.second) return false;
	}

	return true;
}

int main() {
	int n, m;
	while (~scanf("%d%d", &n, &m)) {
		if (solve(n, m)) printf("%d divides %d!\n", m, n);
		else printf("%d does not divide %d!\n", m, n);
	}
}
