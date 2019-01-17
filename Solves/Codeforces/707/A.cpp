#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

int main() {
	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char c; cin >> c;
			if (c != "B" && c != "W" && c != "G") {
				cout << "#Color\n";
				return 0;
			}
		}

	cout << "#Black&White\n";
	return 0;
}