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
const int MAXN = 1e4 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int qtt[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		qtt[a[i]%m]++;
	}

	for (int i = 0; i < MAXN; i++) if (qtt[i] > 1) {
		cout << 0 << '\n';
		return 0;
	}

	ll ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			ans = ans * abs(a[i] - a[j]) % m;
		}
	}

	cout << ans << '\n';

	return 0;
}