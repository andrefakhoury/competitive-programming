#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y, id;

	Point() {}

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	// sort by y axis
	bool operator<(Point const& pt) const {
		return y < pt.y;
	}
};

inline long long dist(Point a, Point b) {
	long long dx = (a.x - b.y);
	long long dy = (a.y - b.y);

	return dx * dx + dy * dy;
}

int main() {
	int T; scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int n; scanf("%d", &n);
		vector<Point> points(n);

		// just read everything
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &points[i].x, &points[i].y);
			points[i].id = i;
		}
		
		// sort by x axis
		sort(points.begin(), points.end(), [](Point& a, Point& b) {
			return a.x < b.x;
		});
		
		set<Point> vis = { points[0] };

		int last = 0; // last visited point
		long long h = 1e9; // best distance (squared to minimize errors)
		pair<int, int> best;

		// go through all points 
		for (int i = 1; i < n; i++) {
			// delete useless points (outside the range [i.x - h, i.x]
			while (last < i && points[i].x - points[last].x > h) vis.erase(points[last]), last++;

			// search for closest point on y range [i.y - h, i.y + h]
			for (auto it = vis.lower_bound(Point(points[i].x - h, points[i].y - h)); it != vis.end() && points[i].y + h >= it->y; it++) {
				long long curDist = dist(points[i], *it);

				if (curDist < h) {
					h = curDist;
					best.first = it->id;
					best.second = i;
				}
			}

			// point `i` is now visited
			vis.insert(points[i]);
		}

		printf("Case %d: The shortest distance is %.3lf\n", t, sqrt(h));	
	}


	return 0;
}
