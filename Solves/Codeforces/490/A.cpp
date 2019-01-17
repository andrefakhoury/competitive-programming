#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

int main() {
	int n; cin >> n;
	vector<int> p(n);
	vector<int> ind[4];
	for (int i = 0; i < n; i++)	{
		cin >> p[i];
		ind[p[i]].push_back(i+1);
	}

	int teams = min(ind[1].size(), min(ind[2].size(), ind[3].size()));
	cout << teams << "\n";
	for (int i = 0; i < teams; i++) {
		cout << ind[1][i] << " " << ind[2][i] << " " << ind[3][i] << "\n";
	}
	return 0;
}