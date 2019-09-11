#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
	ll x, y;

	Point () {}
	Point (ll x, ll y) {
		this->x = x;
		this->y = y;
	}

	// this + p
	Point operator+ (Point p) const {
		return Point(p.x + x, p.y + y);
	}

	// this - p
	Point operator- (Point p) const {
		return Point(x - p.x, y - p.y);
	}

	// Multiply by constant
	Point operator* (ll k) const {
		return Point(x*k, y*k);
	}

	// Dot product
	ll operator* (Point p) const {
		return x * p.x + y * p.y;
	}

	// Cross product <this, p>
	ll operator^ (Point p) const {
		return x * p.y - y * p.x;
	}

	// this < p
	bool operator< (Point p) const {
		return x == p.x ? y < p.y : x < p.x;
	}

	// this == p
	bool operator== (Point p) const {
		return x == p.x && y == p.y;
	}

	// this != p
	bool operator!= (Point p) const {
		return x != p.x || y != p.y;
	}

	ll dist2 (Point p) {
		return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);
	}

	string toString() {
		return "(" + to_string(x) + ", " + to_string(y) + ")";
	}
};

bool cmp(Point a, Point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(Point a, Point b, Point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(Point a, Point b, Point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) >= 0;
}

void convex_hull(vector<Point>& a) {
	if (a.size() == 1) return;

	sort(a.begin(), a.end(), cmp);
	Point p1 = a[0], p2 = a.back();
	vector<Point> up, down;
	up.push_back(p1);
	down.push_back(p1);
	for (int i = 1; i < (int)a.size(); i++) {
		if (i == a.size() - 1 || cw(p1, a[i], p2)) {
			while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back(a[i]);
		}
		if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
			while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back(a[i]);
		}
	}

	a.clear();
	for (int i = 0; i < (int)up.size(); i++)
		a.push_back(up[i]);
	for (int i = down.size() - 2; i > 0; i--)
		a.push_back(down[i]);
}
