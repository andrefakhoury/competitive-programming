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

vector<pii> bombs;
int n;
int P;

struct Node {
	int ac, dc;
	int L = -1, R = -1;

	Node() {}
	Node(int a, int b) : ac(a), dc(b) {}
};

vector<Node> seg;

inline bool getRange(int l, int r) {
	auto it = lower_bound(bombs.begin(), bombs.end(), pii(l, 0));
	return it != bombs.end() && it->first <= r;
}

int build(int i, int j) {
	int p = seg.size();
	seg.eb(0, 0);

	if (!getRange(i, j)) return p; 

	if (i == j) {
		auto it = lower_bound(bombs.begin(), bombs.end(), pii(i, 0));

		for(; it != bombs.end() && it->first <= j; it++) {
			if (it->second) seg.back().ac++;
			else seg.back().dc++;
		}
	} else {
		int m = (i + j) / 2;
		int L = build(i, m);
		int R = build(m+1, j);
		seg[p].ac += seg[L].ac + seg[R].ac;
		seg[p].dc += seg[L].dc + seg[R].dc;
		seg[p].L = L;
		seg[p].R = R;
	}

	return p;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;

	bombs.resize(n);
	for (int i = 0; i < n; i++) cin >> bombs[i].fi >> bombs[i].se;
	sort(bombs.begin(), bombs.end());





	return 0;
}