#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	vector<ll> a(n+1);
	for (int i = 0; i < n; i++) cin >> a[i];
	a[n] = INF;

	ll ans = 100;

	ll stocks = 0;
	ll money = 100;
	for (int i = 0; i < n; i++) {
		if (a[i+1] > a[i]) { // vende tudo e compra de novo
			money += stocks * a[i];
			ans = max(ans, money);
			stocks = 0;
			ll qtt_to_buy = money / a[i];
			qtt_to_buy = min(qtt_to_buy, 100000ll);
			money -= qtt_to_buy * a[i];
			stocks += qtt_to_buy;
		} else if (a[i+1] < a[i]) { // vende tudo, deixa pra comprar na proxima
			money += stocks * a[i];
			stocks = 0;
		}

		ans = max(ans, money);
	}

	cout << ans << "\n";
}