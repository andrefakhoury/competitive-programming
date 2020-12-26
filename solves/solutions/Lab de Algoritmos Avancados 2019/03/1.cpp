#include <stdio.h>
#include <vector>
using namespace std;

const int MAXN = 20;

bool isUsed(int i, int bmask) {
	return bmask & (1 << i);
}

int newBMask(int bmask, int i) {
	return bmask | (1 << i);
}

bool isPrime(int x) {
	for (int i = 2; i < x; i++) if (x%i == 0) return false;
	return true;
}

vector<int> cur;
int n;

void solve(int qtd, int num, int bmask) {
	if (qtd == n) {
		if (isPrime(1+num)) {
			for (int i : cur) printf("%d ", i);
			printf("\n");
			return;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (isUsed(i, bmask)) continue;

		if (isPrime(num+i)) {
			cur.push_back(i);
			solve(qtd+1, i, newBMask(bmask, i));
			cur.pop_back();
		}
	}
}

int main() {
	int ncase = 0;
	while (~scanf("%d", &n)) {
		if (ncase != 0) printf("\n");
		printf("Case %d:\n", ++ncase);
		cur.push_back(1);

		solve(1, 1, newBMask(0, 1));

		cur.clear();
	}
}