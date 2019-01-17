#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int main() {
	int n, x; cin >> n;
	deque<int> c;
	for (int i = 0; i < n; i++) {
		cin >> x;
		c.push_back(x);
	}

	int a = 0, b = 0, i = 0;
	while(c.size()) {
		int op1 = c.front();
		int op2 = c.back();

		if (op1 > op2) c.pop_front();
		else c.pop_back();

		if (i%2) b += max(op1, op2);
		else a += max(op1, op2);

		i++;
	}

	cout << a << " " << b << endl;
}