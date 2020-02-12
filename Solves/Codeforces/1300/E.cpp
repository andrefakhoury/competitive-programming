#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct cosa {
	double val, tot;
	int ind;

	cosa(double a, double b, int c) : val(a), tot(b), ind(c) {}

	bool operator<(cosa const& b) const {
		return val == b.val ? ind > b.ind : val > b.val;
	}
};

pair<double, int> find(pair<double, int> const& a, pair<double, int> const& b) {
	double x1 = a.fi / a.se;
	double x2 = b.fi / b.se;
	return x1 < x2 ? a : b;
}

double a[MAXN];
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		a[i] = x;
	}

	vector<cosa> pq;
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		pq.emplace_back(sum/i, sum, i);
	}
	sort(pq.begin(), pq.end());

	for (auto i : pq)
		printf("%.5lf %.5lf %d\n", i.val, i.tot, i.ind);

	sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= i; j--) {
			
		}

		while(pq.back().ind < i) pq.pop_back();
		double ans = (pq.back().tot - sum) / (pq.back().ind - i + 1);
		printf("%.10lf\n", ans);

		sum += a[i];
		for (int j = i+1; j <= pq.back().ind; j++) {
			printf("%.10lf\n", ans);
			sum += a[j];
			i = j;
		}
	}

	return 0;
}