#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, k; cin >> n >> k;

	long long ans = LLONG_MAX;
	for (long long i = 1; i < k; i++) {
		if ((n)%i == 0) {
			long long x = (n*k)/i + i;
			ans = min(ans, x);
		}
	}

	cout << ans << endl;
}