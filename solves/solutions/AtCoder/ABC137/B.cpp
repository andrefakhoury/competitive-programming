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
	int k, x; cin >> k >> x;
	int kk = k;

	vector<int> ans;
	for (int i = x; k && i <= 1000000; i++, k--)
		ans.pb(i);

	k = kk-1;
	for (int i = x-1; k && i >= -1000000; i--, k--)
		ans.pb(i);

	sort(ans.begin(), ans.end());
	for (int i : ans) cout << i << ' ';
	cout << '\n';
	

	return 0;
}