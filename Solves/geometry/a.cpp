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
	return sqrt(P.x*P.x + P.y*P.y);
}

int main () {
	ll x, y, z, w;
	cin >> x >> y >> z >> y;
	cout << sqrt((double)x*x+y*y+z*z+w*w);

	return 0;
}