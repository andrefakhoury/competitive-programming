#include <bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> v;

int main() {
	int n, x; cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
		v.pb(x);
	}

	sort(v.begin(), v.end(), greater<int>());

	int ans = 0;
	long long mine = 0;
	for (int i = 0; i < n; i++) {
		sum -= v[i];
		mine += v[i];
		ans++;

		if (mine > sum) {
			cout << ans << endl;
			return 0;
		}
	}
	cout << n << endl;
	return 0;
}