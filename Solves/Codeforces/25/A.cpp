#include <bits/stdc++.h>
using namespace std;

int a[105];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int e = 0, o = 0, ev;
	for (int i = 1; i <= n; i++) {
		if (a[i]%2) o++;
		else e++;
	}
	if (e > o) ev = 1;
	else ev = 0;

	for (int i = 1; i <= n; i++) {
		if (a[i]%2 == ev) {
			cout << i << endl;
			return 0;
		}
	}
}