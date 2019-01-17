#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[105];
	int n; cin >> n;
	int posm = 1, posM = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] <= a[posm]) posm = i;
		if (a[i] > a[posM])  posM = i;
	}

	if (posm > posM) cout << n-posm + posM-1 << endl;
	if (posm < posM) cout << n-posm + posM-1 - 1 << endl;

	return 0;
}