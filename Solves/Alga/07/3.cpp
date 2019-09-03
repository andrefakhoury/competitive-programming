#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> divi(int n) {
	vector<int> ret;
	for (int i = 1; i * i <= n; i++) {
		if (n%i == 0) {
			ret.push_back(i);
			if (i*i != n) ret.push_back(n/i);
		}
	}
	return ret;
}

int lcm(int a, int b) {
	return a/ __gcd(a, b) * b;
}

int solve(int n) {
	vector<int> div = divi(n);

	set<pair<int, int> > st;

	for (int i : div) {
		for (int j : div) {
			if (lcm(i, j) == n)
				st.insert({min(i, j), max(i, j)});
		}
	}

	return st.size();
}

int main() {
	int n;
	while(scanf("%d", &n), n) {
		printf("%d %d\n", n, solve(n));
	}
}