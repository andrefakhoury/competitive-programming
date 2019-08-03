#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 3e5 + 5;
vector<ll> a, diff;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, k; cin >> n >> k;
	a.resize(n);
	diff.resize(n-1);

	for (ll& i : a) cin >> i;
	for (int i = 1; i < n; i++) diff[i-1] = a[i-1] - a[i];
	sort(diff.begin(), diff.end());

	ll ans = a[n-1] - a[0];
	for (int i = 0; i < k-1; i++) ans += diff[i];

	cout << ans << endl;
}