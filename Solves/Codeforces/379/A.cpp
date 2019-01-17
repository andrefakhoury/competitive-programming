#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b; cin >> a >> b;
	long long ans = 0;

	int used = 0;
	while(a) {
		a--;
		used++;

		if (used == b) {
			a++;
			used = 0;
		}

		ans++;
	}

	cout << ans << endl;
}