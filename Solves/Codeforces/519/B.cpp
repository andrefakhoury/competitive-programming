#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

int main() {
	int n; cin >> n;
	ll x, s1 = 0, s2 = 0, s3 = 0;

	for (int i = 1; i <= n; i++) {
		cin >> x;
		s1 += x;
	}

	for (int i = 1; i <= n-1; i++) {
		cin >> x;
		s2 += x;
	}

	for (int i = 1; i <= n-2; i++) {
		cin >> x;
		s3 += x;
	}

	cout << s1-s2 << endl << s2-s3 << endl;


	
	return 0;
}