#ifndef CP_GEOMETRY_HPP
#define CP_GEOMETRY_HPP

#include <bits/stdc++.h>

/**
 * 2-Dimensional Point
 * @tparam T type of coordinates
 * @tparam D type of floating points (used in distances and stuff)
 */
template <typename T=long long, typename D=double>
class Point {
public:
	T x, y;

	Point();
	Point(T x, T y);

	template<typename Tp, typename Dp>
	inline Point<T, D> operator-(Point<Tp, Dp> const& rhs);

	template<typename Tp, typename Dp>
	inline Point<T, D> operator+(Point<Tp, Dp> const& rhs);

	template<typename Tp>
	inline Point<T, D> operator/(Tp k);

	template<typename Tp>
	inline Point<T, D> operator*(Tp k);
};

template <typename T, typename D>
Point<T, D>::Point() : x{}, y{} {}

template <typename T, typename D>
Point<T, D>::Point(T x, T y) : x{x}, y{y} {}

template<typename T, typename D> template<typename Tp, typename Dp>
inline Point<T, D> Point<T, D>::operator-(const Point<Tp, Dp> &rhs) {
	return Point(x - rhs.x, y - rhs.y);
}

template<typename T, typename D> template<typename Tp, typename Dp>
inline Point<T, D> Point<T, D>::operator+(const Point<Tp, Dp> &rhs) {
	return Point(x + rhs.x, y + rhs.y);
}

template<typename T, typename D> template<typename Tp>
inline Point<T, D> Point<T, D>::operator/(Tp k) {
	return Point<T, D>(x/k, y/k);
}

template<typename T, typename D> template<typename Tp>
inline Point<T, D> Point<T, D>::operator*(Tp k) {
	return Point<T, D>(x*k, y*k);
}

template <typename T, typename D> inline T len2(Point<T, D> const& p) {
	return p.x * p.x + p.y * p.y;
}

template <typename T, typename D> inline D len2(Point<T, D> const& p) {
	return sqrt(p.x * p.x + p.y * p.y);
}

#endif //CP_GEOMETRY_HPP
