#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

int main() {
	int n, k, x; cin >> n >> k;
	int num = 0;

	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (5 - x - k >= 0) num++;
	}

	cout << num/3 << endl;
}
