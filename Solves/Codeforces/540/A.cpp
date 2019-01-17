#include <bits/stdc++.h>
using namespace std;

int move1(char a, char b) {
	int x = a - "0";
	int y = b - "0";
	return (x - y + 10)%10;
}

int move2(char a, char b) {
	int x = a - "0";
	int y = b - "0";
	return (y - x + 10)%10;
}

int main() {
	int n; cin >> n;
	string ini, fim; cin >> ini >> fim;

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += min(move1(ini[i], fim[i]), move2(ini[i], fim[i]));
	cout << ans << endl;
}
