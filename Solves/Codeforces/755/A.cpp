#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 * 1000 + 2;
bool isNotPrime[MAXN];

void crivoAtenagoras(int n) {
	for (int i = 2; i < n; i++)
		if (!isNotPrime[i])
			for (int j = 2*i; j < n; j += i)
				isNotPrime[j] = true;
}

int main() {
	crivoAtenagoras(MAXN);

	int n; scanf("%d", &n);
	for (int m = 1; m <= 1000; m++)
		if (isNotPrime[n*m+1]) return !printf("%d\n", m);

	printf("%d\n", rand()%1000+1); //heheh
	return 0;
}