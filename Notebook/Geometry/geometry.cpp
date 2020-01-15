#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Point {
	T x, y;

	Point() : x(), y() {}
	Point(T x, T y) : x(x), y(y) {}

	Point operator+(Point p) { return {x+p.x, y+p.y}; } // adicao simples
	Point operator-(Point p) { return {x-p.x, y-p.y}; } // subtracao simples
	Point operator*(T val) { return {x*val, y*val}; } // produto por escalar
	Point operator/(T val) { return {x/val, y/val}; } // divisao por escalar
	T operator^(Point p) { return x*p.y - y*p.x; } // produto vetorial (cross product) [aligned:0; left:+; right:-] |v||w|sin
	T operator*(Point p) { return x*p.x + y*p.y; } // produto escalar (dot product) [90 graus:0; <90 graus:+; >90 graus:-] |v||w|cos

	Point perp() { return {y, -x}; } // perpendicular
	T sq() { return x * x + y * y; } // norma ao quadrado
	double abs() { return sqrt(this->sq()); } // norma
	Point translate(Point v) { return (*this) + v; } // translacao
	Point scale(Point c, double factor) { return c + (*this - c) * factor; } // escala o vetor atual de acordo com o centro c
	Point rot(double a) { return {x*cos(a) - y*sin(a), x*sin(a) + y*cos(a)}; }; // rotacionar anti-horario 'a' graus

	bool operator< (Point const& p) const { return x == p.x ? y < p.y : x < p.x; }
	bool operator> (Point const& p) const { return x == p.x ? y > p.y : x > p.x; }
	bool operator==(Point const& p) const { return x == p.x && y == p.y; }
	bool operator!=(Point const& p) const { return x != p.x || y != p.y; }

	friend ostream& operator<<(ostream& out, Point const& p) {
		return out << p.x << ' ' << p.y;
	}
};

// // returns 1, 0 or -1 (positive, 0 or negative)
// template<typename T> int sgn(T x) {
// 	return (T(0) < x) - (x < T(0));
// }

// // orientacao de AB em relacao a AC (left: > 0; right: < 0; aligned: 0)
// template<typename T> T orient(Point<T> a, Point<T> b, Point<T> c) {
// 	return (b-a)^(c-a); // orient(a, b, c) = orient(c, a, b) = orient(b, c, a)
// }

// // returns if p is in angle formed by ABxAC
// bool inAngle(Point a, Point b, Point c, Point p) {
// 	// assert(orient(a, b, c) != 0); // there is no angle
// 	if (orient(a, b, c) < 0) swap(b, c);
// 	return orient(a, b, p) >= 0 && orient(a, c, p) <= 0;
// }

int main() {
	Point<double> p;
	cout << p << '\n';
}