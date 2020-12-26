#include <iostream>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

struct Point {
	int x, y;

	Point() {}
	Point(int a, int b) {
		x = a, y = b;
	}

	void read() {
		scanf("%d%d", &x, &y);
	}

	int dist(Point p) {
		return abs(p.x - x) + abs(p.y - y);
	}
};

int memo[1 << 11][30][30];

int solve(int vis, int n, Point last, vector<Point>& a, Point st) {
	if (vis == (1 << n) - 1) return st.dist(last);

	int& ret = memo[vis][last.x][last.y];
	if (~ret) return ret;

	int ans = INT_MAX;
	for (int k = 0; k < n; k++) {
		if (vis & (1 << k)) continue;
		ans = min(ans, solve(vis | (1 << k), n, a[k], a, st) + last.dist(a[k]));
	}

	return ret = ans;
}

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		memset(memo, -1, sizeof memo);

		int X, Y; scanf("%d%d", &X, &Y);

		Point st; st.read();
		int n; scanf("%d", &n);
		vector<Point> a(n);
		for (int i = 0; i < n; i++) a[i].read();
		printf("The shortest path has length %d\n", solve(0, n, st, a, st));
	}
}