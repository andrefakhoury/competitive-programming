#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& i : a) cin >> i;

		sort(a.begin(), a.end());

		cout << min(n - 2, a[n-2]-1) << '\n';
	}

}