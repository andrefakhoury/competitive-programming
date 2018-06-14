#include <bits/stdc++.h>

#define ll long long

using namespace std;

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
	ll x, y, z, w;

	scanf("%lld %lld %lld %lld", &x, &y, &z, &w);
	Point u(z-x, w-y);

	scanf("%lld %lld %lld %lld", &x, &y, &z, &w);
	Point v(z-x, w-y);

	printf("%.9lf %.9lf\n", Length(u), Length(v));
	printf("%.9lf %.9lf\n", (double)(u+v).x, (double)(u+v).y);
	printf("%.9lf %.9lf\n", (double)(u*v), (double)(u^v));
	printf("%.9lf\n", (double)0.5*(double)abs(u^v));
	return 0;
}