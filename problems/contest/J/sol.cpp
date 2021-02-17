#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) print(__VA_ARGS__), print('\n')

const int MAXN = 3e5 + 5;
int n;
int a[MAXN][10];
vector<int> pos[4 * MAXN];

void solve(int actual) {
	auto can = [](int i, int left, int up)->pii {
		pii ans = {-1, -1};
		for (int j = 2; j < 6; j++) {
			if (a[i][j] == up && a[i][j+1] == left) {
				return {a[i][j - 1], a[i][j + 2]};
			}
		}
		return ans;
	};

	vector<int> up(n + 10);
	int left = 0;

	int width = -1, height = n;
	vector<vector<int>> ans;

	vector<int> vis(n + 1);

	auto find_next = [&can, &vis](int left, int up, int current) {
		for (int idx : pos[max(left, up)]) if (idx != current && !vis[idx]) {
			if (can(idx, left, up).fi != -1) return idx;
		}
		return -1;
	};

	for (int i = 1; i <= height; i++) {
		ans.emplace_back();
		for (int j = 1; ; j++) {
			ans.back().emplace_back(actual);
			if (up[j] == 0 && i != 1) return;

			if (vis[actual]) return;
			vis[actual] = true;

			auto [next_left, next_up] = can(actual, left, up[j]);

			if (next_left == -1) return;

			if (next_left == 0) {
				if (width != -1) {
					if (j != width) return;
				} else {
					width = j;
					height = n / width;
					if (n % width) return;
				}

				actual = find_next(0, up[1], actual);
				if (actual == -1 && i != height) return;

				left = 0;
				up[j] = next_up;

				break;
			}

			actual = find_next(next_left, up[j + 1], actual);
			if (actual == -1) return;

			left = next_left;
			up[j] = next_up;
		}
	}

	for (int i = 1; i <= width; i++) if (up[i] != 0) return;
	if (left != 0) return;

	print(height, width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	exit(0);
}



inline void run_test(int test_number) {
	rd(n);
	vector<int> allx; allx.reserve(4 * n);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 4; j++) {
			rd(a[i][j]);
			allx.push_back(a[i][j]);
		}
		for (int j = 4; j < 8; j++) {
			a[i][j] = a[i][j-4];
		}
	}

	sort(allx.begin(), allx.end());
	allx.erase(unique(allx.begin(), allx.end()), allx.end());

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 8; j++) {
			a[i][j] = lower_bound(allx.begin(), allx.end(), a[i][j]) - allx.begin();
		}
	}

	vector<int> actual[5];
	for (int i = 1; i <= n; i++) {
		int cnt0 = 0;
		for (int j = 0; j < 4; j++) {
			cnt0 += a[i][j] == 0;
			pos[a[i][j]].push_back(i);
		}
		actual[cnt0].push_back(i);
	}

	for (int sz = 4; sz >= 1; sz--) {
		if (actual[sz].size()) {
			solve(actual[sz][0]);
			break;
		}
	}

	print("impossible");
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}