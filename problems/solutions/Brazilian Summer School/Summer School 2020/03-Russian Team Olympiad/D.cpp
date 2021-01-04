#include <bits/stdc++.h>
using namespace std;

#define mk make_pair
#define fi first
#define se second

const int MAXN = 1e3 + 5;
typedef pair<int, int> pii;

int n, m;

int sum[MAXN][MAXN];
pii rng[MAXN];
string str;

inline void init() {
	for (int i = 1; i <= n; i++)
		rng[i] = {1, m};
}

inline void update_sum() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
			if (rng[i].fi <= j && rng[i].se >= j) sum[i][j]++;
		}
	}
}

inline void set_sum(int l1, int r1, int l2, int r2) {
	if (l1 > l2) swap(l1, l2);
	if (r1 > r2) swap(r1, r2);

	for (int i = l1; i <= l2; i++) {
		rng[i].fi = max(rng[i].fi, r1+1);
		rng[i].se = min(rng[i].se, r2-1);
	}
}

inline void dc(int i, int j) {
	set_sum(i, j, 1, m);
}

inline void eb(int i, int j) {
	set_sum(i, j, n, 1);
}

inline int get_sum(int l1, int r1, int l2, int r2) {
	if (l1 > l2) swap(l1, l2);
	if (r1 > r2) swap(r1, r2);

	l1 = max(l1, 1), l2 = min(l2, n);
	r1 = max(r1, 1), r2 = min(r2, m);
	
	return sum[r2][l2] - sum[l2][r1-1] - sum[l1-1][r2] + sum[l1-1][r1-1];
}

inline string get_route() {
	update_sum();
	int i = 1, j = 1;

	str.clear();
	while(i != n || j != m) {
		bool ci = true;

		int di = get_sum(i-1, j+1, n, 1);
		int dj = get_sum(i+1, j-1, 1, m);

		ci = di >= dj;
		if (i == n) ci = false;
		if (j == m) ci = true;

		if (ci) {
			str.push_back('D');
			i++;
		} else {
			str.push_back('R');
			j++;
		}
	}
	return str;
}

inline void ask() {
	cout << "? " << get_route() << endl;
}

inline void answer() {
	cout << "! " << get_route() << endl;
	exit(0);
}

inline void correct() {
	update_sum();
	int k; cin >> k;

	map<pii, bool> mp;
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		mp[{x, y}] = true;
	}

	int i = 1, j = 1;

	bool last = 0;
	for (char c : str) {
		if (mp[{i, j}]) {
			if (last == 0) { // foi pra baixo
				dc(i-1, j+1);
			} else { // direita
				eb(i+1, j-1);
			}

			last = c == 'D' ? 0 : 1;
		} else {
			if (last == 0) { // foi pra baixo
				eb(i, j);
			} else { // direita
				dc(i, j);
			}
		}

		if (c == 'D') i++;
		else j++;
	}
}

int main() {
	cin >> n >> m;

	init();
	for (int i = 1; i <= 10; i++)
		ask(), correct();
	answer();
}