#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d ", &n);
	int qt1 = 0;

	for (int i = 0; i < n; i++) {
		char c; scanf("%c", &c);
		qt1 += c == "1";
	}

	return !printf("%d\n", abs(n - 2*qt1));
}
