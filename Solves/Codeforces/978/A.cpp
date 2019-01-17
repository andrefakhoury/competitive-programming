#include <bits/stdc++.h>

using namespace std;

int num[1005];

int main() {
	
	int n, x;
	vector<int> vec, vecr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		num[x]++;
		vecr.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		num[vecr[i]]--;
		if (num[vecr[i]] == 0) {
			vec.push_back(vecr[i]);
		}
	}
	
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
	
	
	return 0;
}
