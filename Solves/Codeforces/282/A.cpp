#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define debugg(a) cout << ">>" << (#a) << " : " << (a) << endl;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, ans = 0;
	string l;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l;
		if (l.find("+") != string::npos) ans++;
		else ans--;
	}
	cout << ans << endl;
	return 0;
}