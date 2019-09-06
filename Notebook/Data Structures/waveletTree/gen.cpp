#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MMA = 2e9;

int main() {
	int n = 1e5, q = 5e3;
	cout << n << ' ' << q << '\n';
	for (int i = 0; i < n; i++) {
		cout << int(rng() % MMA - (MMA/2)) << ' ';
 	}
 	cout << '\n';
 	while(q--) {
 		int l = rng() % n + 1;
 		int r = rng() % (n - l + 1) + l;
 		while (r > n) {
 			l = rng() % n + 1;
 		}

 		cout << l << ' ' << r << ' ' << rng() % (r - l + 1) + 1 << '\n';
 	}
}