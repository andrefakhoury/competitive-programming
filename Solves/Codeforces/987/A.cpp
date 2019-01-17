#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define debugg(a) cout << ">>" << (#a) << " : " << (a) << endl;

using namespace std;

int gem[6];

int main() {
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "purple") gem[0] = 1;
		if (s == "green") gem[1] = 1;
		if (s == "blue") gem[2] = 1;
		if (s == "orange") gem[3] = 1;
		if (s == "red") gem[4] = 1;
		if (s == "yellow") gem[5] = 1;
	}

	int ans = 6;
	for (int i = 0; i < 6; i++) {
		ans -= gem[i];
	}

	cout << ans << "\n";
	if (gem[0] == 0) cout << "Power\n";
	if (gem[1] == 0) cout << "Time\n";
	if (gem[2] == 0) cout << "Space\n";
	if (gem[3] == 0) cout << "Soul\n";
	if (gem[4] == 0) cout << "Reality\n";
	if (gem[5] == 0) cout << "Mind\n";

	return 0;
}