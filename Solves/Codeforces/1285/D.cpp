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
const int MAXL = 31;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Trie {
	int val = -1;
	int b;
	map<int, Trie> mp;

	Trie() {
		mp.clear();
	}

	void add(int x, int b = 30) {
		this->b = b;
		if (b == -1) val = 0;
		else mp[(x & (1 << b)) != 0].add(x, b-1);
	}

	int solve() {
		if (~val) return val;
		if (!mp.count(0)) val = mp[1].solve();
		else if (!mp.count(1)) val = mp[0].solve();
		else val = min(mp[0].solve(), mp[1].solve()) + (1 << b);
		return val;
	}
};

int main() {
	int n; scanf("%d", &n);

	Trie root;
	while(n--) {
		int x; scanf("%d", &x);
		root.add(x);
	}

	printf("%d\n", root.solve());
}