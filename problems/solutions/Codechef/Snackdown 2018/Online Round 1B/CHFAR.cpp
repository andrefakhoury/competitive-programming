#include <bits/stdc++.h>
using namespace std;


int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n, k; cin >> n >> k;
		int x, qt = 0;
		while(n--) {
			cin >> x;
			if (x > 1) qt++;
		}
		if (qt <= k) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}