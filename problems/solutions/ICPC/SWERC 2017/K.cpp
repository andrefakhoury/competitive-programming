/* Behind geometry.cpp */
#include <bits/stdc++.h>

using namespace std;

#define mk make_pair
#define pb push_back
#define fi first
#define se second

typedef pair<int, int> ii;
typedef long long ll;

const long double EPS = 1e-9;
const long double PI = acos(-1.0);

ll gcd (ll a, ll b) {
	if (!b)
		return a;
	else
		return gcd(b, a%b);
}

template <class T>
class Point {
public:
	T x, y;

	Point () { }

	Point (T x, T y) : x(x), y(y) {}

	/**/
	bool operator == (const Point &b) const {
		return (abs (x - b.x) < EPS and abs (y - b.y) < EPS);
	}

	/**/
	bool operator < (const Point &b) const {
		return ((x < b.x) or ((x == b.x) and y < b.y));
	}

	//Produto vetorial
	// p^q = |p|*|q|*sin(ang)	ang: directed ang from p to q(-PI < ang <= PI)
	// p^q = 0 => ang = 0 or PI, p and q are colinear
	// p^q > 0 => 0 < ang < PI / p^q < 0 => -PI < ang < 0
	// p^q = directed area of paralelogram formed by vectors p and q
	// dist point p to line ab = ||ab^p|| / ||ab||
	T operator ^ (const Point &b) const {
		return (this->x * b.y) - (this->y * b.x); 
	}

	//Produto escalar
	// p*q = |p|*|q|*cos(ang)	ang: inner ang (0 <= ang < PI)
	// p*q = 0 => ang = 90 / p*q > 0 => ang < 90 / p*q < 0 => ang > 90
	// p*p = |p|^2  => |p| = sqrt(p*p)
	T operator * (const Point &b) const {
		return (this->x * b.x) + (this->y * b.y);
	}

	/**/
	Point operator * (T k) const {
		return Point (x*k, y*k);
	}

	Point operator / (T k) const {
		if (k == 0) cout << "Class Point (operador /): divisao por zero" << endl;
		return Point (x/k, y/k);
	}
	
	/**/
	Point operator + (const Point &b) const {
		return Point (x + b.x, y + b.y);
	}

	/**/
	Point operator - (const Point &b) const {
		return Point (x - b.x, y - b.y);
	}

	/**/
	T len2 () const {
		return x*x + y*y;
	}

	/**/
	long double len () const {
		return sqrt (x*x + y*y);
	}

	/**/
	T dpp2 (const Point &b) const {
		return ((*this)-b)*((*this)-b);
	}

	/*Distancia ponto a ponto*/
	T dpp (const Point &b) const {
		return ((*this)-b).len();
	}

	/*Oriented relative length of projection of this over b*/
	T relative_proj (Point &b) const {
		return ((*this)*b)/(b.len()*b.len());
	}

	Point norm () const {
		return Point (x/this->len(), y/this->len());
	}

	/*Retorna o vetor perpendicular ao vetor (0,0) -> (Point)
	Sentido clockwise*/
	Point perp () const {
		return Point (this->y, -1.0 * this->x);
	}

	// Distancia do ponto p ao segmento ab, tambem retorna por 
	// referencia o ponto (c) do segmento mais perto de p
	T distToSegment (const Point a, const Point b, Point &c) const {
		// formula: c = a + u * ab
		Point p = *this;
		if (a == b) return p.dpp(a);
		Point ap = Point(p - a), ab = Point(b - a);
		T u = ap.relative_proj(ab);
		if (u < 0.0) u = 0.0;
		if (u > 1.0) u = 1.0;
		c = a + ab * u;
		return p.dpp(c);
	}

	// Projection of this over v
	Point proj (const Point &v) const {
		return v*((*this)*v);
	}

	/**/
	Point rotaciona (T ang) const {
		T c = cos(ang), s = sin(ang);
		T X = x*c - y*s;
		T Y = x*s + y*c;
		return Point(X,Y);
	}

	/*area de um poligono concavo ou convexo
	dado vetor de vertices ordenados clockwise ou
	counter clockwise*/
	static T area (vector <Point> v) {
		T area = 0.0;
		for (int i = 0; i < (int)v.size(); i++) 
			area += v[i] ^ v[(i+1)%v.size()];
		return abs(area/2.0);
	}

	/* return counter clock points of convex hull
	 * WITHOUT COLINEAR POINTS*/
	static vector <Point> convex_hull (vector <Point> p) {
		if (p.size() <= 2) return p;

		int n = p.size(), k = 0;
		vector <Point> H(2*n);

		sort(p.begin(), p.end());

		for (int i = 0; i < n; i++) {
			while (k >= 2 and ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= 0.0) k--;
			H[k++] = p[i];
		}

		for (int i = n-2, t = k+1; i >= 0; i--) {
			while (k >= t and ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= 0.0) k--;
			H[k++] = p[i];
		}

		H.resize(k-1);

		return H;
	}
	
	/*Angulo em forma de fracao reduzida entre o vetor Op (p é o ponto)
	 e o eixo x, se paralelo ao eixo x retorna (1,0) ou (-1,0)
	 se paralelo ao eixo y retorna (0,1) ou (0,-1)
	 SÓ FUNCIONA PARA PONTOS INTEIROS*/ 
	static ii ang (Point p) {
		ll a = p.x, b = p.y;
		if (a == 0) return mk(0, b/abs(b));
		else if (b == 0) return mk(a/abs(a), 0);
		return mk(a/gcd(a,b), b/gcd(a,b));
	}

	/*Interseccao de dois vetores somandos a pontos*/
	static T inter (Point p1, Point v1, Point p2, Point v2) {
		if (abs(v2 ^ v1) >= EPS) {
			Point c = p1 - p2;
			return (c ^ v2)/(v2 ^v1);
		} else {
			cout << "Class Point (funcao inter): retas paralelas" << endl;
			cout << "Talvez deva ajustar o EPS" << endl;
		}
		return 0.0;
	}

	/* Retorna se point p esta dentro do poligono convexo v, pontos de v estao
	 * em counter clockwise
	 * Considera borda como fora
	 * O(log2(v.size()))*/
	static bool inside(const vector<Point> &v, const Point &p) {
		// V DEVE ESTAR EM COUNTER CLOCKWISE
		int n = v.size();

		if(n < 3)
			return false;
	
		// Considerar borda como dentro: mudar para <
		if(((v[1]-v[0])^(p-v[0])) <= 0)
			return false;

		int bot = 2, top = n-1;
		int ans = -1;
		while(bot <= top) {
			int mid = (bot+top)>>1;

			// Considerar borda como dentro: mudar para <=
			if(((v[mid]-v[0])^(p-v[0])) < 0) {
				ans = mid;
				top = mid-1;
			} else {
				bot = mid+1;
			}
		}

		if(ans == -1)
			return false;

		// Considerar borda como dentro: mudar para <
		if(((v[ans]-v[ans-1])^(p-v[ans-1])) <= 0)
			return false;

		return true;
	}

	/*Retorna o retangulo (pontos em anti clockwise) que tem a menor valor
	min(Xmax -Xmin, Ymax - Ymin)*/
	static vector <Point> minRetangulo (vector <Point> v) {
		vector <Point> at;
		at.pb(Point(-1e18, -1e18));
		at.pb(Point(1e18, -1e18));
		at.pb(Point(1e18, 1e18));
		at.pb(Point(-1e18, 1e18));
		v = convex_hull(v);
		int n = v.size();
		for (int i = 0; i < n; i++) {
			int j = (i+1)%n;
			Point vec = v[j] - v[i];
			T ang = atan2(vec.y, vec.x);
			vector <Point> ve;
			for (int j = 0; j < n; j++) {
				ve.pb(v[j].rotaciona(ang));
			}
			T minx, miny, maxx, maxy;

			minx = miny = numeric_limits<T>::max();
			maxx = maxy = numeric_limits<T>::min();

			for (int j = 0; j < n; j++) {
				if (ve[j].x < minx) minx = ve[j].x;
				if (ve[j].x > maxx) maxx = ve[j].x;
				if (ve[j].y < miny) miny = ve[j].y;
				if (ve[j].y > maxy) maxy = ve[j].y;
			}
			T mini = min(maxx - minx, maxy - miny);
			if (mini < min(at[2].x - at[0].x, at[2].y - at[0].y)) {
				at.clear();
				at.pb(Point(minx, miny));
				at.pb(Point(maxx, miny));
				at.pb(Point(maxx, maxy));
				at.pb(Point(minx, maxy));
			}
		}

		return at;
	}

	static long double distLine(Point a, Point b, Point p) {
		long double proj = (p - a) * (b - a) / ((b - a).len() * (b - a).len());
		Point<long double> k = Point<long double>(a.x, a.y) + Point<long double>((b - a).x, (b-a).y) * proj;
		return (Point<long double>(p.x, p.y) - k).len(); 
	}

	// distance of 2 farthest points. O(n) + O(convex_hull)
	// Rotating Calipers
	static long double max_dist (vector <Point> p) {
		long double ret = 1e15;
		p = Point::convex_hull(p);

		int n = p.size();
		if (n <= 1)
			return 0;
		if (n == 2)
			return p[0].dpp(p[1]);

		int at = 1;
		for (int i = 0; i < n; i++) {
			int j = (i + 1)%n;

			Point v = p[j] - p[i];
			int nxt = (at + 1)%n;
			while (nxt != i and (v^(p[nxt]-p[i])) >= (v^(p[at]-p[i]))) {
				at = nxt;
				nxt = (at + 1)%n;
			}

			// cout << p[i] << ' ' << p[j] << ' ' << p[at] << endl;
			// cout << distLine(p[i], p[j], p[at])<< endl;
			ret = min (ret, distLine(p[i], p[j], p[at]));
		}

		return ret;
	}

};

template <class T>
ostream &operator<<(ostream &os, Point<T> const &p) {
	return os << p.x << " " << p.y;
}


int main (void) {
	ios_base::sync_with_stdio(false);

	int n, r; cin >> n >> r;

	vector<Point<ll> > pts;
	for(int i = 0; i < n; i++) {
		ll x, y; cin >> x >> y;
		pts.emplace_back(x, y);
	}

	cout << fixed << setprecision(12);
	cout << Point<ll>::max_dist(pts) << endl;

	return 0;
}