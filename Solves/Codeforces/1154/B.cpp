#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	a.erase( unique( a.begin(), a.end() ), a.end() );

	if (a.size() > 3) return !printf("-1");
	if (a.size() == 2) {
		int num = a[1] - a[0];
		if (num%2 == 0) return !printf("%d\n", num/2);
		return !printf("%d\n", num);
	}

	if (a.size() == 1) return !printf("0\n");

	if (a[2] - a[1] == a[1] - a[0]) return !printf("%d\n", a[2] - a[1]);
	return !printf("-1\n");
}