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
	ll x, y;
    for (int i = 0; i < 3; i++) {
        scanf("%ll %ll", &x, &y);
        v.emplace_back(x, y);
    }

    side.emplace_back(v[0].x-v[1].x, v[0].y-v[1].y);
    side.emplace_back(v[1].x-v[2].x, v[1].y-v[2].y);
    side.emplace_back(v[0].x-v[2].x, v[0].y-v[2].y);

    double per = Length(side[0]) + Length(side[1]) + Length(side[2]);
    double area = 0.5*(double)abs(side[1]^side[2]);
    double radius = area/(0.5*per);

    printf("R: %ll\n", radius);

    printf("X1: %ll : Y1: %ll\n", v[0].x, v[0].y);
    printf("X2: %ll : Y2: %ll\n", v[1].x, v[1].y);
    printf("X3: %ll : Y3: %ll\n", v[2].x, v[2].y);

    printf("Mod1: %ll\n", Length(side[0]));
    printf("Mod2: %ll\n", Length(side[1]));
    printf("Mod3: %ll\n", Length(side[2]));

    printf("\n\n");

    double Cy = (radius*Length(side[1])-v[1].y*radius*Length(side[0]))/(v[1].y*v[0].x - v[1].x);



    printf("%.0ll %.0ll %.0ll\n", x, Cy, radius);
	return 0;
}