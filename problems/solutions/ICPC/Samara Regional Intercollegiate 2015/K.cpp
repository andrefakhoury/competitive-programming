#include <bits/stdc++.h>
    
#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define mk make_pair
    
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
    
struct Point {
    ll x, y;
    
    Point() {}
    Point (ll a, ll b) {
        x = a, y = b;
    }
    
    void read() {
        cin >> x >> y;
        if(x > y) swap(x, y);
    }
    
    Point operator-(Point const& p) const {
        return Point(x-p.x, y-p.y);
    }
    
    ll operator^(Point const& p) const {
        return x*p.y - y*p.x;
    }
    
    bool operator<(Point const& p) const {
        return ((*this)^p) > 0;
    }
};

void yes() {
    cout << "YES" << endl;
    exit(0);
}

void no() {
    cout << "NO" << endl;
    exit(0);
}
    
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<Point> vec;
    
    vector<Point> all(n);
    for (auto& p : all) p.read();
    
    for (int i = n-2; i >= 0; i--) {
        vec.eb(all[i] - all[i+1]);
    }
  
    Point baixo = Point(1, 0);
    n--;
    for(int i = 0; i < n; ++i) {
        if(vec[i].y <= 0 and vec[i].x >= 0) {
            if((vec[i] ^ baixo) > 0) {
                baixo = vec[i];
            }
        }
    }

    int flag = 1;
    for(int i = 0; i < n; ++i) {
        flag = flag and ((baixo ^ vec[i]) >= 0);
    }
    if(flag) yes();
    else no();
    
    return 0;
}