#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int N = 1000007, inf = 0x3f3f3f3f;

map<int, int> tim[N];

int special[N], vis[N];

int solve(vector<ii> & vec, int cur, int count_special = false) {
	memset(vis, 0, sizeof vis);

	set<int> active;
	int ans = 0;
	for(ii aux : vec) {
		int t, id;
		tie(t, id) = aux;

		if(id < 0) {
			// entrando
			active.insert(-id);
		} else {
			if(vis[id]) continue;
			if(!count_special and special[id]) {
				active.erase(id);
				continue;
			}
			if(special[id] and t == cur) {
				active.erase(id);
				continue;
			}

			ans++;
			for(int x : active) {
				vis[x] = 1;
			}
			active.clear();
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, w, h;

	cin >> n >> w >> h;

	int cur = 0;
	for(int i = 1; i <= w; ++i) {
		tim[i][0] = ++cur;
	}

	for(int i = 1; i <= h; ++i) {
		tim[w][i] = ++cur;
	}


	for(int i = w-1; i >= 0; --i) {
		tim[i][h] = ++cur;
	}

	for(int i = h-1; i >= 0; --i) {
		tim[0][i] = ++cur;
	}

	vector<ii> vec;

	auto add_interval = [&](int i, int t1, int t2) {
		if(t1 > t2) { // eh especial
			special[i] = 1;
			// inicio
			vec.eb(0, -i);
			vec.eb(t2, i);

			// fim
			vec.eb(t1, -i);
			vec.eb(cur, i);
		} else {
			vec.eb(t1, -i);
			vec.eb(t2, i);
		}
	};

	for(int i = 1; i <= n; ++i) {
		int x, y, x1, x2, y1, y2;
		char d;
		cin >> x >> y >> d;
		if(d == 'S') {
			x1 = x - min(x, y);
			y1 = y - min(x, y);
			int t1 = tim[x1][y1];
			assert(t1);

			x2 = x + min(w - x, y);
			y2 = y - min(w - x, y);
			int t2 = tim[x2][y2];
			assert(t2);

			add_interval(i, t1, t2);

		} else if(d == 'E') {
			x1 = x + min(w - x, y);
			y1 = y - min(w - x, y);
			int t1 = tim[x1][y1];
			assert(t1);

			x2 = x + min(w - x, h - y);
			y2 = y + min(w - x, h - y);
			int t2 = tim[x2][y2];
			assert(t2);

			add_interval(i, t1, t2);

		} else if(d == 'N') {
			x1 = x + min(w - x, h - y);
			y1 = y + min(w - x, h - y);
			int t1 = tim[x1][y1];
			assert(t1);

			x2 = x - min(x, h - y);
			y2 = y + min(x, h - y);
			int t2 = tim[x2][y2];
			assert(t2);

			add_interval(i, t1, t2);

		} else {
			x1 = x - min(x, h - y);
			y1 = y + min(x, h - y);
			int t1 = tim[x1][y1];
			assert(t1);

			x2 = x - min(x, y);
			y2 = y - min(x, y);
			int t2 = tim[x2][y2];
			assert(t2);

			add_interval(i, t1, t2);
		}
	}

	sort(vec.begin(), vec.end(), [](ii a, ii b) {
		int s1, s2;
		s1 = a.se > 0;
		s2 = b.se > 0;
		if(a.fi == b.fi and s1 == s2) {
			int x1 = special[abs(a.se)];
			int x2 = special[abs(b.se)];
			return x1 < x2;
		}
		return a < b;
	});

	int ans1 = solve(vec, cur, false);

	for(int i = 1; i <= n; ++i) {
		if(special[i] and vis[i] == 0) special[i] = 0;
	}
	int ans2 = solve(vec, cur, false);

	cout << min(ans2, ans1 + 1) << endl;

}