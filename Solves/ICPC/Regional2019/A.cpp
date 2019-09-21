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
const int maxn = 1e3 + 5;

struct Circle {
	ll x, y, r;

	bool touches(Circle const& rhs) const {
		ll dist2 = (rhs.x-x)*(rhs.x-x) + (rhs.y-y)*(rhs.y-y);
		return dist2 <= (r+rhs.r)*(r+rhs.r);
	}
};

struct Dsu {
	vector<int> pai, w;

	Dsu(int n) : pai(n+1), w(n+1, 1) {
		iota(pai.begin(), pai.end(), 0);
	}

	int find(int x) {
		if (x == pai[x]) return x;
		return pai[x] = find(pai[x]);
	}

	void join(int x, int y) {
		x = find(x), y = find(y);

		if (x == y) return;
		if (w[x] < w[y]) swap(x, y);
		pai[y] =x;
		w[x] += w[y];
	}

	bool con(int x, int y) {
		return find(x) == find(y);
	}
};

Circle v[maxn];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int m, n, k;
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) cin >> v[i].x >> v[i].y >> v[i].r;

	Dsu dsu(k+4);

	for (int i = 0; i < k; i++) {
		if (v[i].x <= v[i].r) dsu.join(i, k); // oeste
		if (v[i].x+v[i].r >= m) dsu.join(i, k+1); // leste
		if (v[i].y <= v[i].r) dsu.join(i, k+2); // norte
		if (v[i].y+v[i].r >= n) dsu.join(i, k+3); // sul
	}

	for (int i = 0; i < k; i++) {
		for (int j = i+1; j < k; j++) {
			if (v[i].touches(v[j])) {
				dsu.join(i, j);
			}
		}
	}

	if (dsu.con(k, k+1) or dsu.con(k, k+2)  or dsu.con(k+1, k+3) or dsu.con(k+2, k+3))
		cout << "N\n";
	else cout << "S\n";

	return 0;
}