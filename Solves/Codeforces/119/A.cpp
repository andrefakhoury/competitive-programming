#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

int main() {
	int a[2]; cin >> a[0] >> a[1];
	int n; cin >> n;
	while(true) {
		for (int i = 0; i < 2; i++) {
			if (n - __gcd(a[i], n) >= 0) n -= __gcd(a[i], n);
			else {
				cout << 1 - i << endl;
				return 0;
			}
		}
	}
}
