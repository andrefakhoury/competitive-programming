#include <bits/stdc++.h>
using namespace std;

char oposto(char c) {
	if (c == 'U') return 'D';
	if (c == 'D') return 'U';
	if (c == 'R') return 'L';
	if (c == 'L') return 'R';
	return 'D';
}

const int MAXN = 100005;

map<char, set<int> > mp;
bool used[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s; cin >> s;

	if (s.size() % 2) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < s.size(); i++) {
		mp[s[i]].insert(i);
	}

	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (used[i]) continue;
		if (mp[oposto(s[i])].size() == 0) ans++;
		else {
			used[*(mp[oposto(s[i])].begin())] = true;
			mp[oposto(s[i])].erase(mp[oposto(s[i])].begin());
		}

		mp[s[i]].erase(i);
		used[i] = true;
	}

	printf("%d\n", ans/2);
}