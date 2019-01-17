#include <bits/stdc++.h>
#define debugg(x) cout << ">>" << (#x) << " :: " << (x) << endl

using namespace std;

int main(void) {
	ios :: sync_with_stdio(false);
	int n, qti = 0;
	string gg;
	
	cin >> n >> gg;
	
	for (int i = 0; i < n; i++) {
		if (gg[i] == "1") qti++;
		if (qti == 1 || gg[i] == "0") {
			cout << gg[i];
		}
	}
	
	cout << "\n";
	
	return 0;
}
