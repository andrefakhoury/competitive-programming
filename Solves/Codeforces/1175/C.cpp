#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for (int& i : a) cin >> i;

		if (n == 1 || k == 0) {
			cout << a[0] << '\n';
			continue;
		}

		int best = INT_MAX, ind = -1;
		for (int i = k; i < n; i++) {
			int lo = a[i-k], hi = a[i];
			int mi = (lo + hi) / 2;

			int cur = max(mi - lo, hi - lo);
			if (cur < best) best = cur, ind = mi;
		}

		cout << ind << '\n';
	}

	return 0;
}