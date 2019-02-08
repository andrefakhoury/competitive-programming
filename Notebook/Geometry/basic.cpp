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