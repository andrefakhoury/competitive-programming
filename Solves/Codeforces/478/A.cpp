#include <bits/stdc++.h>
using namespace std;

int main() {
	int sum = 0, x;
	for (int i = 0; i < 5; i++) {
		cin >> x;
		sum += x;
	}

	if (sum%5 || !sum) cout << -1 << endl;
	else cout << sum/5 << endl;
}
