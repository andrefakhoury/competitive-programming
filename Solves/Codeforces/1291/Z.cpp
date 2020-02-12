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

	while(s.size() && (s.back() - '0') % 2 == 0) {
		s.pop_back();
	}

	if (!s.size()) {
		cout << -1 << '\n';
		return;
	}

	ll sum = 0;
	for (char c : s) {
		sum += c - '0';
	}

	int j = -1;
	if (sum%2 != 0) {
		for (int i = 0; i < s.size(); i++) {
			if ((s[i] - '0') % 2 != 0) {
				j = i;
				break;
			}
		}
	}

	if (j == (int)s.size()-1) {
		cout << -1 << '\n';
		return;
	} else {
		for (int i = 0; i < s.size(); i++) {
			if (i == j) continue;
			cout << s[i];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) _solve();
	

	return 0;
}