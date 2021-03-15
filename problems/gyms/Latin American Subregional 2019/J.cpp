#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

#define KK 14

int card(char c) {
	if (c == 'A') return 1;
	if (c >= '1' && c <= '9') return c - '0';
	if (c == 'D') return 10;
	if (c == 'Q') return 11;
	if (c == 'J') return 12;
	if (c == 'K') return 13;

	return 0;
}

void won(int i) {
	cout << i << '\n';
	exit(0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, k; cin >> n >> k;
	vector<vector<int> > a(n);

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (char c : s) a[i].push_back(card(c));

		if (i == k - 1) continue;

		// checa se ganhou
		vector<int> freq(15);
		for (int j = 0; j < 15; j++) freq[j] = 0;
		for (int j : a[i]) {
			freq[j]++;
			if (freq[j] == 4 && a[i].size() == 4) won(i + 1);
		}

	}

	bool can = false;
	int cur = k-1, passou = KK;
	while(true) {
		a[cur].pb(passou);

		vector<int> freq(15);

		// checa se ganhou
		for (int i = 0; i < 15; i++) freq[i] = 0;
		for (int i : a[cur]) {
			freq[i]++;
			if (freq[i] == 4 && a[cur].size() == 4) won(cur + 1);
		}

		vector<pii> all;
		for (int i = 0; i < 15; i++) {
			if (freq[i]) all.eb(freq[i], i);
		}

		sort(all.begin(), all.end());

		int which = -1;
		if (can && freq[KK]) { // passa o coringa
			which = KK;
			can = false;
		} else {
			which = all[0].second == KK ? all[1].second : all[0].second;
			can = true;
		}

		vector<int> ok;
		for (int i = 0, foi = 0; i < (int) a[cur].size(); i++) {
			if (a[cur][i] == which && !foi) {
				foi = 1;
				continue;
			} else {
				ok.push_back(a[cur][i]);
			}
		}

		passou = which;

		a[cur] = ok;

		// checa se ganhou
		for (int i = 0; i < 15; i++) freq[i] = 0;
		for (int i : a[cur]) {
			freq[i]++;
			if (freq[i] == 4 && a[cur].size() == 4) won(cur + 1);
		}

		cur = (cur + 1) % n;
	}

	return 0;
}