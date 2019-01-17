#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
	int x; cin >> x;
	for (int a = 1; a <= x; a++) {
		for (int b = 1; b <= x; b++) {
			if (a%b == 0 && a*b > x && a/(float)b < (float)x)
				return !printf("%d %d\n", a, b);
		}
	}
	return !printf("-1\n");
}