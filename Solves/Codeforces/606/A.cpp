#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> a(3), x(3);
	for (int& i : a) cin >> i;
	for (int& i : x) cin >> i;

	int cur = 0;
	for (int i = 0; i < 3; i++) {
		if (a[i] > x[i]) cur += (a[i] - x[i]) / 2;
	}

	int left = 0;
	for (int i = 0; i < 3; i++) {
		if (a[i] < x[i]) cur -= x[i] - a[i];
		if (cur < 0) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	return 0;
}