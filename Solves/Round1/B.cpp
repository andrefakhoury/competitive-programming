#include <bits/stdc++.h>

using namespace std;

int main(void) {
	long long int n;
	cin >> n;
	
	while (true) {
		if (n%2 == 1) {
			cout << n << endl;
			return 0;
		} else {
			n = n/2;
		}
	}
	
	return 0;
	
}