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

vector<Point> ship;

int inTriangle(Point a, Point b, Point c, Point p) {
    ll Cross1 = (p-a)^(b-a);
    ll Cross2 = (p-b)^(c-b);
    ll Cross3 = (p-c)^(a-c);

    if (Cross1 >= 0 && Cross2 >= 0 && Cross3 >= 0) return 1;
    if (Cross1 <= 0 && Cross2 <= 0 && Cross3 <= 0) return 1;
    return 0;
}

map<piii, int> dp;

int hitShip(Point r) {
    dp.clear();

    for (int i = 0; i < ship.size(); i++) {
        for (int j = i+1; j < ship.size(); j++) {
            for (int z = j+1; z < ship.size(); z++) {
                if (dp[{{i, j}, z}]) return 1;
                if (inTriangle(ship[i], ship[j], ship[z], r))
                    return dp[{{i, j}, z}] = dp[{{i, z}, j}] = dp[{{j, i}, z}] = dp[{{j, z}, i}] = dp[{{z, i}, j}] = dp[{{z, j}, i}] = 1;
            }
        }
    }
    return 0;
}

int binSearch(Point p) {
    int l = 1, r = int(ship.size())-1;

    while(l < r) {
        int mid = (l+r)/2;

        Point u = ship[mid] - ship[0];
        Point v = p-ship[0];
        ll cross = u^v;
        
        u = ship[mid+1]-ship[0];
        ll cross2 = u^v;

        if (cross >= 0 && cross2 <= 0) return inTriangle(ship[0], ship[mid], ship[mid+1], p);
        else if (cross > 0 && cross2 > 0) l = mid+1;
        else r = mid;
    }
    return 0;
}

int main () {
	int n, m, k, ans = 0;
    ll x, y;
    Point rock;

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &x, &y);
        ship.emplace_back(x, y);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld %lld", &rock.x, &rock.y);
        ans += binSearch(rock);
    }

    return !printf("%s\n", (ans >= k) ? "YES" : "NO");
}