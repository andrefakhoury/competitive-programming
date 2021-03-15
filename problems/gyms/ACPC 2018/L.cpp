#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

const int N = 1000007, inf = 0x3f3f3f3f;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
	freopen("looking.in", "r", stdin);
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;

	while(t--) {
		int n, k; cin >> n >> k;
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			int a; cin >> a;
			ans |= a;
		}
		cout << ans << '\n';
	}
}