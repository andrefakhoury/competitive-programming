#include <bits/stdc++.h>
using namespace std;

#define max(a, b) (a > b ? a : b)

int main() {
	long long n; cin >> n;

	long long all = 0, qtt;
	for (long long i = 1; i <= n; i *= 2) {
		qtt = i*5;
		all += qtt;

		if (n <= all) {
			long long ant = all - qtt;
			long long final = n - ant;

			if (final <= i) cout << "Sheldon\n";
			else if (final <= 2*i) cout << "Leonard\n";
			else if (final <= 3*i) cout << "Penny\n";
			else if (final <= 4*i) cout << "Rajesh\n";
			else if (final <= 5*i) cout << "Howard\n";

			return 0;
		}
	}	
}
