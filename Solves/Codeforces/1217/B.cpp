#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

ll DIV(ll a, ll b) {
	return (a + b - 1) / b;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;
	while(t--) {
		long long n, x; cin >> n >> x;

		long long ans = INF;
		vector<long long> a(n), h(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> h[i];
		}

		ll maxi = 0;
		for (int i = 0; i < n; i++) {
			maxi = max(maxi, a[0]);
		}

		for (int i = 0; i < n; i++)
			if (h[i] < a[i]) {
				ans = min(ans, 1 + DIV(x-maxi, a[i] - h[i]));
			}

		if (ans < 0) ans = 1;
		cout << (ans < INF ? ans : -1) << '\n';
	}

	return 0;
}

