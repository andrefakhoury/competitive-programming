#include <bits/stdc++.h>
using namespace std;

struct point {
	int x, y;

	bool operator<(point p) {
		if (x == p.x) return y < p.y;
		return x < p.x;
	}
}

int main() {
	int n; cin >> n;
	vector<point> pos;
	while(n--) {
		int x, y; cin >> x >> y;
		pos.emplace_back(x, y);
	}

	return 0;
}