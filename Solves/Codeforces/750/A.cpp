#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	int available = 4*60 - k, p = 1;

	while(available - 5*p >= 0) {
		available -= 5*p;
		p++;
		if (p > n) break;
	}

	cout << p-1 << endl;
}
