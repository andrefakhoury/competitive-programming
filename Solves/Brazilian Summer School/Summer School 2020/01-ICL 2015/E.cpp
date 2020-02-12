#include <bits/stdc++.h>
using namespace std;

const int MAXX = 2.5e4;

struct Point {
	int x, y;

	Point() {}
	Point(int x, int y) : x(x), y(y) {}

	Point operator+(Point const& p) const { return Point(x+p.x, y+p.y); }
	Point operator-(Point const& p) const { return Point(x-p.x, y-p.y); }
	Point operator*(int const& k) const { return Point(x*k, y*k); }
	int operator^(Point const& p) const { return x*p.y - y*p.x; }
	Point operator~() { return Point(y, -x); }
	bool operator<(Point const& p) const {
		return x == p.x ? y < p.y : x < p.x;
	}
};

vector<Point> convex_hull(vector<Point> a) {
	sort(a.begin(), a.end());
	vector<Point> upper, down;
	for (int i = 0; i < (int)a.size(); i++) {
		while(upper.size() >= 2 && ((upper[upper.size()-1] - upper[upper.size()-2]) ^ (a[i] - upper[upper.size()-2])) < 0)
			upper.pop_back();
		upper.push_back(a[i]);

		while(down.size() >= 2 && ((down[down.size()-1] - down[down.size()-2]) ^ (a[i] - down[down.size()-2])) > 0)
			down.pop_back();
		down.push_back(a[i]);
	}
	a.clear();
	for (int i = 0; i < (int)up.size(); i++)
		a.push_back(up[i]);
	for (int i = down.size() - 2; i > 0; i--)
		a.push_back(down[i]);
	return a;
}

struct pt_dble {
	double x, y;

	pt_dble() {}
	pt_dble(double x, double y) : x(x), y(y) {}

	void print() {
		printf("%.7lf %.7lf\n", x, y);
	}
};

struct rect {
	pt_dble vx[4];
	double area;

	rect() {
		for (int i = 0; i < 4; i++) {
			vx[i].x = vx[i].y = 0;
		}
		area = 0;
	}

	rect(pt_dble a, pt_dble b, pt_dble c, pt_dble d) {
		vx[0] = a, vx[1] = b, vx[2] = c, vx[3] = d;

		area = 0;
		for (int i = 0, j = 3; i < 4; j = i, i++)
			area += (vx[i].x + vx[j].x) * (vx[j].y - vx[i].y);
		area = abs(area / 2.0);
	}

	bool operator<(rect const& a) const {
		return area < a.area;
	}

	void print() {
		for (int i = 0; i < 4; i++)
			v[i].print();
	}
};

rect get_enclosing(Point p0, Point p1, vector<Point>& a) {
	rect ans;
	Point v = p1 - p2;

	for (int i = 0; i < (int)a.size(); i++) {
		
	}

}

int main() {
	int n; scanf("%d", &n);
	vector<Point> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}

	vector<Point> v = convex_hull(a);
	v.push_back(v.front());

	rect ans(pt_dble(-MAXX, MAXX), pt_dble(MAXX, MAXX), pt_dble(MAXX, -MAXX), pt_dble(-MAXX, -MAXX));

	for (int i = 1; i < (int)v.size(); i++) {
		ans = min(ans, get_enclosing(v[i], v[i-1], a));
	}

	ans.print();
}