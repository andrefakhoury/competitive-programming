#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	bool can = true;

	if (a != d) can = false;
	if (c > 0 and a == 0) can = false;

	printf("%d\n", can);
	return 0;
}
