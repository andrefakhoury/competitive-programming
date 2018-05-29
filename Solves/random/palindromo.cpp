#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string p;
	int x = 0;

	int i, j;

	cin >> n;
	cin >> p;

	for (i = 0, j = n-1; i<j; i++, j--) {
		if (p[i] != p[j]) {
			x++;
		}
	}

	printf("%d\n", x);

	return 0;
}