//The famous CAVERNOSO PROBLEM

#include <bits/stdc++.h>

using namespace std;
	
map<int, int> cav;

int main() {
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		cav[s.size()]++;
	}
	int max = s.size();
	//for (int i = 1; i < cav.size(); i++) {
	for (auto it = cav.begin(); it != cav.end(); it++)
		if (it->second > cav[max]) max = it->first;
	cout << max << "\n";
}