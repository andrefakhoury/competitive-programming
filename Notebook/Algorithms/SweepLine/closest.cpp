#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const double EPS = 1e-6;

struct Point {
	double x, y;
	int id;

	Point() {}

	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

	// sort by y axis
	bool operator<(Point const& pt) const {
		return y == pt.y ? x < pt.x : y < pt.y;
	}
};

inline double dist(Point a, Point b) {
	double dx = (a.x - b.y);
	double dy = (a.y - b.y);

	return sqrt(dx * dx + dy * dy);
}

int main() {
	int n; scanf("%d", &n);
	vector<Point> points(n);

	// just read everything
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &points[i].x, &points[i].y);
		points[i].id = i;
	}
	
	// sort by x axis
	sort(points.begin(), points.end(), [](Point& a, Point& b) {
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	});
	
	set<Point> vis = { points[0] };

	int last = 0; // last visited point
	double h = 1e9; // best distance (squared to minimize errors)
	pair<int, int> best;

	// go through all points 
	for (int i = 1; i < n; i++) {
		// delete useless points (outside the range [i.x - h, i.x]
		while (last < i && points[i].x - points[last].x > h) vis.erase(points[last]), last++;

		// search for closest point on y range [i.y - h, i.y + h]
		for (auto it = vis.lower_bound(Point(points[i].x - h - EPS, points[i].y - h - EPS)); it != vis.end() && points[i].y + h + EPS >= it->y; it++) {
			double curDist = dist(points[i], *it);

			if (curDist < h) {
				h = curDist;
				best.first = it->id;
				best.second = points[i].id;
			}
		}

		// point `i` is now visited
		vis.insert(points[i]);
	}

	int id1 = min(best.first, best.second);
	int id2 = max(best.first, best.second);

	// printf("%d %d %.6lf\n", best.first, best.second, sqrt(h));
	printf("%d %d %.6lf\n", id1, id2, h);

	return 0;
}
