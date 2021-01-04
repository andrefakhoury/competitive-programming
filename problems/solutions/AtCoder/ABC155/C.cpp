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

	map<string, int> f;
	int maxi = 0;
	vector<string> ans;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		f[s]++;

		if (f[s] > maxi) {
			maxi = f[s];
			ans.clear();
			ans.pb(s);
		} else if (f[s] == maxi) {
			ans.pb(s);
		}
	}

	sort(ans.begin(), ans.end());
	for (string& s : ans ) cout << s << '\n';

	return 0;
}