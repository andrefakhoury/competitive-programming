#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e5 + 5;

char inverse(char i) {
	if (i == 'R') return 'P';
	if (i == 'P') return 'S';
	if (i == 'S') return 'R';
	return 'S';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;

	for (int cases = 1; cases <= t; cases++) {
		int n; cin >> n;
		set<string> st;

		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			st.insert(s);
		}

		bool impossible = false;

		string ans;
		for (int i = 0; i < 500; i++) {
			if (st.empty()) break;

			set<char> cur;
			for (string s : st) {
				int k = i%((int)s.size());
				cur.insert(s[k]);
			}

			if (cur.size() == 3) {
				impossible = true;
				break;
			}

			char c1 = *(cur.begin());
			char c2 = *(cur.rbegin());

			char chosen;
			if (c1 == c2) {
				chosen = inverse(c1);
			} else if (inverse(c1) == c2) {
				chosen = c2;
			} else if (inverse(c2) == c1 ){
				chosen = c1;
			}

			ans += chosen;

			for (string s : st) {
				int k = i%((int)s.size());
				if (inverse(s[k]) == chosen) {
					st.erase(s);
				}
			}
		}

		cout << "Case #" << cases << ": ";
		if (impossible || st.size()) cout << "IMPOSSIBLE\n";
		else cout << ans << '\n';
	}

	return 0;
}