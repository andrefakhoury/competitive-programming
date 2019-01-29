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

int orientation(Point& p, Point& q, Point& r) {
	ll val = (q-p)^(r-q);
	return val > 0 ? 1 : 2; //clock or counterclock
}

int quadrant(Point& p) {
	return p.x >= 0 && p.y >= 0 ? 1 : p.x < 0 && p.y >= 0 ? 2 :
			  p.x < 0 && p.y < 0 ? 3 : 4;
}

Point l;
bool radialCmp(Point& a, Point& b) {
	if (a == l || b == l) return a == l;

	int qdA = quadrant(a);
	int qdB = quadrant(b);

	if (qdA != qdB) return qdA < qdB;
	if (orientation(a, b, l) != 1) return false;
	return true;
}

vector<Point> convexHull(vector<Point>& vec) {
	vector<Point> ret;
	l = vec[0];
	for (int i = 1; i < (int)vec.size(); i++) {
		l = min(l, vec[i]);

	sort(vec.begin(), vec.end(), radialCmp);

	vector<Point> hull;
	hull.push_back(vec[0]);
	hull.push_back(vec[1]);
	hull.push_back(vec[2]);

	for (int i = 3; i < (int)vec.size(); i++) {

		Point top = hull.back();
		hull.pop_back();

		while (hull.size() > 1 and orientation(hull.back(), top, vec[i]) != 1) {
			top = hull.back();
			hull.pop_back();
		}

		hull.push_back(top);
		hull.push_back(vec[i]);
	}

	set<Point> inHull;
	for (auto h : hull) {
		inHull.insert(h);
	}

	for (auto v : vec) {
		if (inHull.find(v) != inHull.end()) continue;
		ret.push_back(v);
	}

	return ret;
}

int main() {
	int n;

	while(scanf("%d", &n), n != 0) {
		vector<Point> a(n);
		for (int i = 0; i < n; i++) {
			scanf("%lld %lld", &a[i].x, &a[i].y);
		}

		int ans = 0;
		while(a.size() >= 3) {
			a = convexHull(a);
			ans++;
		}

		printf("%s\n", ans%2 ? "Take this onion to the lab!" : 
			"Do not take this onion to the lab!");

		a.clear();
	}
}