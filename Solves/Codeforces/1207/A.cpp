#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		int b, p, f, h, c; cin >> b >> p >> f >> h >> c;

		if (h < c) {
			swap(h, c);
			swap(p, f);
		}

		ll ans = 0;
		int qtt1 = min(b/2, p);
		ans += qtt1 * h;

		b -= 2 * qtt1;
		int qtt2 = min(b/2, f);
		ans += qtt2 * c;

		cout << ans << '\n';
	}



	return 0;
}