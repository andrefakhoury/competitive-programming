#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

bool impossible;
int saldo(string& s) {
	impossible = false;

	int ret = 0;
	stack<char> st;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		} else if (s[i] == ')') {
			if (st.size() == 0) ret++;
			else st.pop();
		}
	}

	if (st.size() && ret) impossible = true;
	if (st.size()) return st.size();
	return -ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<string> b(n+1);

	map<int, int> mp;
	vector<int> pos;

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	for (int i = 1; i <= n; i++) {
		int sd = saldo(b[i]);
		if (impossible) continue;

		if (sd >= 0) pos.pb(sd);
		mp[sd]++;
	}

	int ans = 0;
	for (int i = 0; i < (int)pos.size(); i++) {
		int at = pos[i];
		int tv = -pos[i];

		if (mp[tv]) {
			if (at == tv && mp[tv] == 1) continue;

			ans++;
			mp[at]--;
			mp[tv]--;
		}
	}

	cout << ans << endl;
	return 0;
}