#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

class Vector { 
private: 
    int x, y, z; 
    // 3D Coordinates of the Vector 
  
public: 

	Vector() {}
    Vector(int x, int y, int z) 
    { 
        // Constructor 
        this->x = x; 
        this->y = y; 
        this->z = z; 
    } 

    void read() {
    	rd(x, y, z);
    }

    Vector operator+(Vector v); // ADD 2 Vectors 
    Vector operator-(Vector v); // Subtraction 
    int operator^(Vector v); // Dot Product 
    Vector operator*(Vector v); // Cross Product 
    float magnitude() 
    { 
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); 
    } 
    friend ostream& operator<<(ostream& out, const Vector& v); 
    // To output the Vector 
}; 
  
// ADD 2 Vectors 
Vector Vector::operator+(Vector v) 
{ 
    int x1, y1, z1; 
    x1 = x + v.x; 
    y1 = y + v.y; 
    z1 = z + v.z; 
    return Vector(x1, y1, z1); 
} 
  
// Subtract 2 vectors 
Vector Vector::operator-(Vector v) 
{ 
    int x1, y1, z1; 
    x1 = x - v.x; 
    y1 = y - v.y; 
    z1 = z - v.z; 
    return Vector(x1, y1, z1); 
} 
  
// Dot product of 2 vectors 
int Vector::operator^(Vector v) 
{ 
    int x1, y1, z1; 
    x1 = x * v.x; 
    y1 = y * v.y; 
    z1 = z * v.z; 
    return (x1 + y1 + z1); 
} 
  
// Cross product of 2 vectors 
Vector Vector::operator*(Vector v) 
{ 
    int x1, y1, z1; 
    x1 = y * v.z - z * v.y; 
    y1 = z * v.x - x * v.z; 
    z1 = x * v.y - y * v.x; 
    return Vector(x1, y1, z1); 
} 
  
// Display Vector 
ostream& operator<<(ostream& out, 
                    const Vector& v) 
{ 
    out << v.x << "i "; 
    if (v.y >= 0) 
        out << "+ "; 
    out << v.y << "j "; 
    if (v.z >= 0) 
        out << "+ "; 
    out << v.z << "k" << endl; 
    return out; 
} 
  
// calculate shortest dist. from point to line 
float shortDistance(Vector line_point1, Vector line_point2, 
                    Vector point) 
{ 
    Vector AB = line_point2 - line_point1; 
    Vector AC = point - line_point1; 
    float area = Vector(AB * AC).magnitude(); 
    float CD = area / AB.magnitude(); 
    return CD; 
} 

inline void _solve_(int __ntest__) {
	vector<Vector> o1(4);
	vector<Vector> o2(4);

	for (int i = 0; i < 4; i++) o1[i].read();
	for (int i = 0; i < 4; i++) o2[i].read();

	double ans = 1e6;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ans = min(ans, o1[i].dist(o2[j]));
		}
	}

	printf("%.6lf\n", ans);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}