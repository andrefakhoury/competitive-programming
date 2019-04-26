#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d, maxi = -1;
	cin >> a >> b >> c >> d;
	maxi = max({a, b, c, d});

	if (maxi - a > 0) cout << maxi - a << " ";
	if (maxi - b > 0) cout << maxi - b << " ";
	if (maxi - c > 0) cout << maxi - c << " ";
	if (maxi - d > 0) cout << maxi - d << " ";
	cout << endl;
}