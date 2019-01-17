#include <bits/stdc++.h>

#define ll long long

using namespace std;
#define MAXN 100000

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

struct Point{
    ll x, y;
   
    Point() {}
   
    Point(ll x, ll y){
        this->x = x;
        this->y = y;
    }
   
    Point operator+(Point p2) const{
        return Point(x + p2.x, y + p2.y);
    }
   
    Point operator-(Point p2) const{
        return Point(x - p2.x, y - p2.y);
    }
   
    Point operator*(ll c) const{
        return Point(x * c, y * c);
    }
   
    ll operator*(Point p) const{
        return x*p.x + y*p.y;
    }
   
    ll operator^(Point p) const{
        return x*p.y - y*p.x;
    }
};

double Length(Point P) {
    return sqrt((double)P.x*P.x + (double)P.y*P.y);
}

int main () {
	ll x, y, s, n; scanf("%lld%lld", &x, &y);
	Point home(x, y);
	long double m = 0x3f3f3f3f, l;

	scanf("%lld", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &x, &y, &s);
		Point taxi(x, y);
		l = Length(taxi-home)/s;
		if (l < m) m = l;
	}
	printf("%.20Lf\n", m);

}