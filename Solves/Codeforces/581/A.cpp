#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

int main() {
	int a, b; cin >> a >> b;
	int ans1 = 0, ans2 = 0;

	while(a && b) {
		ans1++;
		a--;
		b--;
	}

	while(a > 1) {
		ans2++;
		a -= 2;
	}

	while(b > 1) {
		ans2++;
		b -= 2;
	}

	cout << ans1 << " " << ans2 << endl;
}
