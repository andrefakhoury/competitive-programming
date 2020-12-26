#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct pt {
    ll x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == (int)a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == (int)a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    for (int i = 0, j = 0; i < (int)a.size() && j < (int)up.size(); i++) {
    	if (a[i].x == up[j].x && a[i].y == up[j].y) {
    		j++;
    		continue;
    	}
    }

    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

int main() {
	int n;
	while(scanf("%d", &n), n != 0) {
		vector<pt> points(n);
		vector<int> vis(n, 0);

		for(int i = 0; i < n; i++) {
			scanf("%lld%lld", &points[i].x, &points[i].y);
		}

		for (int i = 0; i < n; i++) {
			printf("(%lld, %lld)\n", points[i].x, points[i].y);
		}
		printf("\n\n");
		convex_hull(points);

		for (int i = 0; i < points.size(); i++) {
			printf("(%lld, %lld)\n", points[i].x, points[i].y);
		}

		// if(resp%2 == 0) printf("Do not take this onion to the lab!\n");
		// else printf("Take this onion to the lab!\n");
	}
}