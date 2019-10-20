#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	int n = rng()%1000000;
	for (int i = 0; i < n; i++) {
		cout << char(rng()%26 + 'a');
	}
}