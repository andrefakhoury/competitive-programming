template<typename T> struct Point3D {
	T x, y, z;

	static constexpr EPS = 1e-12;

	Point3D() : x(), y(), z() {}
	Point3D(T x, T y, T z) : x(x), y(y), z(z) {}
	template<typename Tp> Point3D(Point3D<Tp> p) : x(p.x), y(p.y), z(p.z) {}

	// basic operators
	template<typename Tp> Point3D<T> operator+(Point3D<Tp> const& p) const { return Point3D<T>(x + p.x, y + p.y, z + p.z); }
	template<typename Tp> Point3D<T> operator-(Point3D<Tp> const& p) const { return Point3D<T>(x - p.x, y - p.y, z - p.z); }
	template<typename Tp> Point3D<T> operator*(Tp&& p) const { return Point3D<T>{x * p, y * p, z * p}; }
	template<typename Tp> Point3D<T> operator/(Tp&& p) const { return Point3D<T>{x / p, y / p, z / p}; }
	template<typename Tp> Point3D<T> operator%(Tp&& p) const { return Point3D<T>{x % p, y % p, z % p}; }

	template<typename Tp> Point3D<T>& operator+=(Point3D<Tp> const& p) { return (*this) = (*this) + p; }
	template<typename Tp> Point3D<T>& operator-=(Point3D<Tp> const& p) { return (*this) = (*this) - p; }
	template<typename Tp> Point3D<T>& operator*=(Tp&& p) { return (*this) = (*this) * p; }
	template<typename Tp> Point3D<T>& operator/=(Tp&& p) { return (*this) = (*this) / p; }
	template<typename Tp> Point3D<T>& operator%=(Tp&& p) { return (*this) = (*this) % p; }

	template<typename Tp> bool operator<(Point3D<Tp> const& p) const { return x == p.x ? y == p.y ? z < p.z : y < p.y : x < p.x; }
	template<typename Tp> bool operator==(Point3D<Tp> const& p) const { return x == p.x && y == p.y && z == p.z; }

	inline T len2() const { return x * x + y * y + z * z; }
	inline double len() const { return sqrt(len2()); }

	template<typename Tp> inline T dist2(Point3D<Tp> const& p) const { return (*this - p).len2(); }
	template<typename Tp> inline double dist(Point3D<Tp> const& p) const { return (*this - p).len(); }

	template<typename Tp> inline T dot(Point3D<Tp> const& p) const { return x * p.x + y * p.y + z * p.z; }
	template<typename Tp1, typename Tp2> inline T dot(Point3D<Tp1> const& a, Point3D<Tp2> const& b) const { return (a - *this).dot(b - *this); }

	/** Cross product <*this, p>
		|  i  j  k |
		|  x  y  z |
		| px py pz | */
	template <typename Tp> inline Point3D<T> cross(Point3D<Tp> const& p) const { return Point3D<T>(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x); }
	
};
	template <typename Tp> inline static char sign(Tp x) { return abs(x) < EPS ? 0 : x > 0 ? 1 : -1; }

	/** Orientation of (*this) according to segment AB. 0: collinear, 1: right, -1: left */
	inline char orientation(Point const& a, Point const& b) const { return sign((*this - b).cross(b - a)); }

	/** Orthogonal projection of vector (*this) on vector u.
	 * The point of projection of AB on AC will be at A + AC * AB.proj(AC). */
	inline double proj(Point const& u) const { return static_cast<double>(u.dot(*this)) / u.len2(); }

	/** Distance from (*this) to segment AB */
	inline double dist_to_segment(Point const& a, Point const& b) const {
		Point p = *this;
		if (a.dist2(b) <= EPS) return p.dist(a);
		Point<double> ap = p - a, ab = b - a;
		// if projection doesnt lie on segment, the minimum distance will be to A or B
		double u = clamp(ap.proj(ab), 0., 1.);
		Point<double> c = ab * u + a;
		return p.dist(c);
	}

	/** Checks whether point (*this) is in segment AB */
	inline bool in_segment(Point const& a, Point const& b) const {
		Point<T> AB = b - a, AP = (*this) - a;
		return sign(AB.cross(AP)) == 0 && AB.dot(AP) >= 0 && AB.dot(AP) <= AB.len2();
	}
};