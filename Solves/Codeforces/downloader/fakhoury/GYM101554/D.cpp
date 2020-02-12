#include <bits/stdc++.h>
using namespace std;
 const double EPS = 1e-9;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
class Point 
{
 public:
  T x, y;
   Point () { }
   Point (T x, T y) : x(x), y(y) {}
  bool operator == (const Point &b) const {
   return (abs (x - b.x) < EPS and abs (y - b.y) < EPS);
  }
   /**/
  bool operator < (const Point &b) const {
   return ((x < b.x) or ((x == b.x) and y < b.y));
  }
   //Produto vetorial
  // p^q = |p|*|q|*sin(ang) ang: directed ang from p to q(-PI < ang <= PI)
  // p^q = 0 => ang = 0 or PI, p and q are colinear
  // p^q > 0 => 0 < ang < PI / p^q < 0 => -PI < ang < 0
  // p^q = directed area of paralelogram formed by vectors p and q
  // dist point p to line ab = ||ab^p|| / ||ab||
  T operator ^ (const Point &b) const {
   return (this->x * b.y) - (this->y * b.x); 
  }
   //Produto escalar
  // p*q = |p|*|q|*cos(ang) ang: inner ang (0 <= ang < PI)
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
  T len () const {
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
  static T max_dist (vector <Point> p) 
  {
   T ret = 0;
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
     ret = max (ret, max (p[i].dpp(p[at]), p[j].dpp(p[at])));
   }
    return ret;
  }
};
int main() 
{
 ios::sync_with_stdio(false); cin.tie(NULL);
 int c;
 cin >> c;
 vector<Point <long double > > v;
 for(int i=0;i<c;i++)
 {
  long double a,b; 
  Point<long double> at;
  cin >> a >> b;
  at.x =a ;
  at.y = b;
  v.pb(at);
 }
 Point < long double > aux;
 cout << setprecision(20) << aux.max_dist(v) << endl;
 }