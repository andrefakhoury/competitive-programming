#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int main() {
	long long a, b; cin >> a >> b;

	long long ans = 0;
	while (a <= b) {
		a *= 3;
		b *= 2;
		ans++;
	}

	cout << ans << endl;

}