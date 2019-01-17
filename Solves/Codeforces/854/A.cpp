#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a, b;
	for (a = n; a >= 1; a--) {
		b = n-a;
		if (a < b && __gcd(a, b) == 1) break;
	}

	cout << a << " " << b << endl;
	return 0;
}