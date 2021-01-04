#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e10;
const double EPS = 1e-7;
const int MAXN = 1e3 + 5;

struct Point {
	ll x, y;

	Point() {}

	void read() {
		scanf("%lld%lld", &x, &y);
	}
};

struct Line {
	ll a, b, c; // ax + by + c = 0

	Line() {}

	void read() {
		scanf("%lld%lld%lld", &a, &b, &c);
	}
};

int solve(Point const& A, Point const& B, int const& n, vector<Line> const& v) {

	int ans = 0;
	for (Line const& l : v) {
		// ax + by + c < 0 <---
		// ax + by + c > 0 --->
		bool s1 = A.x * l.a + A.y * l.b + l.c > 0;
		bool s2 = B.x * l.a + B.y * l.b + l.c > 0;
		ans += s1 != s2;
	}

	return ans;
}

int main() {
	Point A; A.read();
	Point B; B.read();
	
	int	n; scanf("%d", &n);
	vector<Line> v(n);

	for (auto& l : v) l.read();
	printf("%d\n", solve(A, B, n, v));
}