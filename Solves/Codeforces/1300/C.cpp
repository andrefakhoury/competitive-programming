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
	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	vector<pii> bt(32);
	int idxAns = 0;

	for (int i = 0; i < n; i++) {
		for (int b = 0; b < 32; b++) {
			if (a[i] & (1 << b)) {
				bt[b].fi++;
				bt[b].se = i;
			}
		}
	}

	for (int i = 31; i >= 0; i--) {
		if (bt[i].fi == 1) {
			idxAns = bt[i].se;
			break;
		}

	}

	cout << a[idxAns] << ' ';
	for (int i = 0; i < n; i++) {
		if (i == idxAns) continue;
		cout << a[i] << ' ';
	}
	cout << '\n';

	return 0;
}