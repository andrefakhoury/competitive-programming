#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	int m; cin >> m;
	string s; cin >> s;

	for (int i = 0, k = 1; i < m; i+=k, k++) {
		cout << s[i];
	}

	cout << endl;
}