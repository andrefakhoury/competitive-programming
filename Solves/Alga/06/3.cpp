#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> a;
	int n;
	NEW_VEC:
	a.clear();
	while (scanf("%d", &n), n != 0) {
		a.push_back(n);
	}

	if (a.size() == 0) return 0;

	sort(a.begin(), a.end());

	int gcd = a[1] - a[0];
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = i+1; j < (int)a.size(); j++) {
			gcd = __gcd(gcd, a[j] - a[i]);
		}
	}

	printf("%d\n", gcd);

	goto NEW_VEC;
}