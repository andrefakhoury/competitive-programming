#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
bool usedX[10005], usedY[10005];
int divisors[10005];

int countDivisors(int x) {
	int ret = 0;
	for (int i = 1; i <= x; i++) {
		if (x%i == 0) ret++;
	}
	return ret;
}

bool check(int x, int y) {
	memset(usedX, 0, sizeof usedX);
	memset(usedY, 0, sizeof usedY);

	int qtX = 0, qtY = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > x && a[i] > y) return false;
		
		if (x%a[i] == 0 && !usedX[a[i]]) {
			usedX[a[i]] = true;
			qtX++;
		} else if (y % a[i] == 0 && !usedY[a[i]]) {
			usedY[a[i]] = true;
			qtY++;
		} else {
			return false;
		}

	}

	return qtX == divisors[x] && qtY == divisors[y];
}

int main() {
	for (int i = 1; i <= 10000; i++) divisors[i] = countDivisors(i);

	scanf("%d", &n); a.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	srand(time(NULL));
	while(true) {
		random_shuffle(a.begin(), a.end());
		if (check(a[0], a[1])) {
			printf("%d %d\n", a[0], a[1]);
			return 0;	
		} 
	}
}