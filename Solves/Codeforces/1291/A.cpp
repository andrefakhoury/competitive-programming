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

inline void _solve() {
	int n; cin >> n;
	string s; cin >> s;

	while(s.size() && (s.back() - '0') % 2 == 0) s.pop_back();

	ll sum = 0;
	for (char c : s) sum += c - '0';

	if (sum%2 != 0) {
		for (int i = 0; i < (int)s.size(); i++) {
			if ((s[i] - '0') % 2 != 0) {
				s.erase(i, 1);
				break;
			}
		}
	}

	string ans;
	for (int i = 0, c = 0; i < (int)s.size(); i++) {
		if (!c && s[i] == '0') continue;
		else ans.push_back(s[i]), c = 1;
	}

	sum = 0;
	for (char c : ans) sum += c - '0';
	if (ans.empty() || sum%2 != 0 || (ans.back()-'0')%2 == 0) {
		cout << -1 << '\n';
	} else cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) _solve();
	return 0;
}