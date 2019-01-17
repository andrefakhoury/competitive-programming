#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int main() {
	int n; cin >> n;
	vector<int> box(n);
	for (int i = 0; i < n; i++) cin >> box[i];

	sort(box.begin(), box.end());

	for (int i = 0; i < n; i++) cout << box[i] << " ";
	cout << endl;
}