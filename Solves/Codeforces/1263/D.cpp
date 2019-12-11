#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct UF {
	int par[30], cnt; 

	UF() {
		for (int i = 0; i < 30; i++) par[i] = i;
		cnt = 0;
	}

	int find(int i) {
		if (par[i] == i) return i;
		return par[i] = find(par[i]);
	}

	void merge(int u, int v) {
		int a = find(u), b = find(v);
		if (a != b) cnt++;
		par[a] = b;
	}
} uf;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	set<char> all;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 1; j < (int)s.size(); j++) {
			uf.merge(s[j]-'a', s[j-1]-'a');
		}
		for (char c : s) all.emplace(c);
	}

	cout << all.size() - uf.cnt << '\n';

	return 0;
}