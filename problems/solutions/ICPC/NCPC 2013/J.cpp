#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
const double pi = acos(-1.0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline double f(double x, double rho2) {
	return exp(-(x*x)/(2.0*rho2)) / (2.0*pi*rho2);
}

const double split_s = 1.2e7;

double integrate(double l, double r, double rho2) {
	double delta = (r-l)/split_s;

	double ans = 0, old = f(l, rho2);
	while (l < r) {
		double x = f(l+delta, rho2);
		ans += (x + old) * l;
		l += delta;
		old = x;
	}

	return ans*pi*delta;
}

int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	double r[7] = {0.0};
	double val[6] = {50.0, 25.0, 10.5, 31.5, 10.5, 21.0};

	for (int i = 1; i < 7; i++) cin >> r[i];

	double rho;
	cin >> rho;

	rho *= rho;
	double ans = 0.0;

	for (int i = 0; i < 6; i++)
		ans += val[i]*integrate(r[i], r[i+1], rho);

	cout.precision(9);
	cout.setf(ios::fixed);

	cout << ans << "\n";
	return 0;
}