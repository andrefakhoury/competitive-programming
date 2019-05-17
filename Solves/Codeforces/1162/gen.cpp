#include <bits/stdc++.h>
using namespace std;

int main () {
	srand(time(NULL));

	int n = 1e5, m = 2e5;
	cout << n << " " << m << endl;
	for (int i = 1; i <= m; i++) {
		cout << (rand()%n) + 1 << ' ' << (rand()%n) + 1 << endl;
	}
}