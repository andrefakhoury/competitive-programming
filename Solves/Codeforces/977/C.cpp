#include <bits/stdc++.h>
#define debugg(x) cout << ">>" << (#x) << " :: " << (x) << endl
using namespace std;
vector<int> seq;
int main(void) {
	ios::sync_with_stdio(false);
	
	int n, k, aa;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> aa;
		seq.push_back(aa);
	}
	
	sort(seq.begin(), seq.end());
	int ans;

	if (k == 0 && seq[0] == 1) ans = -1;
	if (k == 0 && seq[0] != 1) ans = 1;
	if (k != 0) {
		ans = seq[k-1];
		if (k < seq.size() && ans == seq[k]) ans = -1;
	}
	
	cout << ans << endl;
	
	return 0;
}