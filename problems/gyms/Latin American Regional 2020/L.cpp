#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define deb(x) (cout << #x << ": " << x << endl)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e5 + 7, inf = 0x3f3f3f3f;
int evt[N], cnt[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, x; cin >> n >> x;

	for(int i = 0; i < n; i++) {
		int s, d; cin >> s >> d;
		evt[s]++;
		evt[s + d + 1]--;
	}

	int cur = 0;
	for(int i = 0; i < N; i++) {
		cur += evt[i];
		evt[i] = cur;
		cnt[i%x] += cur;
	}

	// for(int i = 0; i < x; i++) {
	// 	cout << cnt[i] << ' ';
	// }
	// cout << '\n';

	ii ans = ii(inf, inf);
	for(int i = 0; i <= 8 * 60; i++) {
		int tot = cnt[i%x];

		ans = min(ans, ii(tot, i));
		cnt[i%x] -= evt[i];
	}

	cout << ans.se << ' ' << ans.fi << '\n';
}