#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

int main() {
	int n, x, y; cin >> n;

	int m = 0, c = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		if (x > y) m++;
		if (y > x) c++;
	}

	if (m > c)  cout << "Mishka\n";
	if (m < c)  cout << "Chris\n";
	if (m == c) cout << "Friendship is magic!^^\n";

	return 0;
}