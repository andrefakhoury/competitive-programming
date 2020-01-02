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
const int MAXN = 2e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	sort(a.begin(), a.end());

	int ans1 = 1;
	for (int i = 0, l = a[0]+1; i < n; i++) {
		if (abs(a[i] - l) >= 2) {
			ans1++;
			l = a[i] + 1;
		}
	}

	set<int> used;
	for (int i = 0; i < n; i++) {
		if (!used.count(a[i]-1)) {
			used.emplace(a[i]-1);
		} else if (!used.count(a[i])) {
			used.emplace(a[i]);
		} else {
			used.emplace(a[i]+1);
		}

	}

	cout << ans1 << ' ' << used.size() << '\n';

	return 0;
}