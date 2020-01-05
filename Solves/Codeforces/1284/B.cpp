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
const int MAXN = 1e6 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class BIT {
	ll bt[MAXN+10];

	public:
	BIT() {
		memset(bt, 0, sizeof bt);
	}

	void update(int i, int val) {
		i++;

		while (i <= MAXN) {
			bt[i] += val;
			i += i&-i;
		}
	}

	ll query(int i) {
		i++;

		ll ret = 0;
		while (i > 0) {
			ret += bt[i];
			i -= i&-i;
		}
		return ret;
	}

	ll query(int i, int j) {
		if (i > j) return 0;
		return query(j) - query(i-1);
	}
};

bool has[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<vector<int> > a(n);
	vector<int> minimo(n);

	int forall = 0;

	vector<int> val;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		a[i].resize(k);

		int mini = INT_MAX, maxi = -1;
		for (auto& j : a[i]) {
			cin >> j;
			if (j > mini) has[i] = true;
			mini = min(mini, j);
			maxi = max(maxi, j);
		}

		minimo[i] = mini;
		forall += has[i];
		if (!has[i]) val.eb(maxi);
	}

	sort(val.begin(), val.end());


	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (has[i]) {
			ans += n;
			continue;
		}

		ll cur = (val.end() - upper_bound(val.begin(), val.end(), minimo[i]));
		cur += forall;
		ans += cur;
	}

	cout << ans << '\n';

	return 0;
}