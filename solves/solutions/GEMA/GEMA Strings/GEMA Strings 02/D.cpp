#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e5 + 5;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	vector<int> z(n);
	for (int i = 0; i < n; i++) cin >> z[i];

	vector<int> pf(n);
	for (int i = 0; i < n; i++) {
		if (z[i]) {
			pf[i + z[i] - 1] = max(pf[i + z[i] - 1], z[i]);
		}
	}
	int cur = 0;
	for (int i = n-1; i >= 0; i--) {
		if (cur > 1 && cur > pf[i]) pf[i] = --cur;
		if (pf[i]) cur = pf[i];
	}

	for (int i : pf) cout << i << ' ';
	cout << '\n';
}