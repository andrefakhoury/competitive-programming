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
const int MAXN = 1e6 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll a[MAXN], n;

struct STT {
	ll ans;
	ll maxi, mini;

	STT() {
		ans = 0;
		maxi = INT_MIN;
		mini = INT_MAX;
	}

	STT(ll a, ll b, ll c) {
		ans = a;
		maxi = b;
		mini = c;
	}

	ll get() {
		if (maxi == INT_MIN) return 0;
		return maxi - mini;
	}
};

STT memo[MAXN][2];

STT best(STT a, STT b) {
	if (a.ans == -1) return b;
	if (b.ans == -1) return a;

	if (a.ans + a.get() == b.ans + b.get()) return a.ans > b.ans ? a : b;
	return (a.ans + a.get()) >= (b.ans + b.get()) ? a : b;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) for (int j = 0; j < 3; j++) memo[i][j].ans = -1;

	// sempre da certo
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < 2; k++) {
			memo[i][0] = best(STT(memo[i-1][k].ans + memo[i-1][k].get(), a[i], a[i]), memo[i][0]);
			memo[i][1] = best(STT(memo[i-1][k].ans, max(memo[i-1][k].maxi, a[i]), min(memo[i-1][k].mini, a[i])), memo[i][1]);
		}
	}

	STT res = best(memo[n][1], memo[n][2]);

	printf("%lld\n", res.ans + res.get());
	
	return 0;
}