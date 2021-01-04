#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define ll long long

typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
const double EPS = 1e-9;
const double PI = acos(-1.0);
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
	T  qqq(const Point &b) const {
		return (this->x * b.y) - (this->y * b.x); 
    }
};

bool calc (pair< Point <double> ,int>  a,pair <Point < double> ,int> b)
{

    Point <double> q1,q2;
    q1 = a.fi;
    q2 = b.fi;
    if(q1.qqq(q2) <= 0.0)
        return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w, h;
    cin >> n >> w >> h;
    while (n != 0 or w != 0 or h != 0)
    {
        vector<pair<Point<double>, int>> v;
        vector<Point <double> >  aux;
        for(int i=0;i<n;i++)
        {
            Point < double> q;
            cin >> q.x >> q.y;
            aux.pb(q);
            
            v.pb(mp(q,i));
        }
        sort(v.begin(),v.end(),calc);
        for(int i=0;i<n/2;i++)
        {
            cout << aux[v[i].se].x << " " << aux[v[i].se].y << endl;
        }
        cin >> n >> w >> h;
    }
    return 0;
}