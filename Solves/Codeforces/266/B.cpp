#include <bits/stdc++.h>
using namespace std;

char f[60];
void change(int n) {
	for (int i = 1; i < n; i++)
		if (f[i] == "B" && f[i+1] == "G") {
			swap(f[i], f[i+1]);
			i++;
		}
}

int main() {
	int n, t; cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> f[i];

	while(t--) change(n);

	for (int i = 1; i <= n; i++) cout << f[i];
	cout << endl;
	return 0;
}