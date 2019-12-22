#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 2001002;

struct Trie {
	int cnt;
	map<char, int> m;

	Trie() {
		cnt = 0;
		m.clear();
	}
};

Trie all[MAXN];
int total = 0;

int ans = 0;

void mark(int i) {
	if (all[i].cnt == 0) ans++;
	all[i].cnt = 1;
}

int add(int ind, string& s, int i) {
	if (!all[ind].m.count(s[i])) {
		all[++total] = Trie();
		all[ind].m[s[i]] = total;	
	}

	return all[ind].m[s[i]];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	string s; cin >> s;
	string pre, suf; cin >> pre >> suf;

	vector<int> op, os;
	for (size_t i = 0, is, k; i < s.size(); i++) {

		is = true, k = 0;
		for (size_t j = i; j < s.size() && k < pre.size(); j++, k++) is &= s[j] == pre[k];
		if (is && k == pre.size()) op.push_back((int)i);

		is = true, k = 0;
		for (size_t j = i; j < s.size() && k < suf.size(); j++, k++) is &= s[j] == suf[k];
		if (is && k == suf.size()) os.push_back((int)i);
	}

	for (int i : op) {
		int last = add(0, s, i), ind = i+1;

		for (int j : os) {
			if (j >= i && j + suf.size() >= i + pre.size()) {
				while(ind <= j) { 
					last = add(last, s, ind);
					ind++;
				}

				mark(last);
			}
		}
	}

	cout << ans << endl;
}