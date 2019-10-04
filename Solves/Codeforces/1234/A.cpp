#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<long long> a(n);

		long long sum = 0;
		for (long long& i : a) {
			cin >> i;
			sum += i;
		}

		long long qtt = (sum + n - 1) / n;
		cout << qtt << '\n';
	}

	return 0;
}