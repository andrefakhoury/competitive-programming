#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;

double f(double a, double b, double c, double d) {
	return a * pow(b, c) + d + d/c;
}

double g(double a, double b, double c, double d) {
	return a * pow(b, c) * log(b) - d/(c*c);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	double n, p, s, v; cin >> n >> p >> s >> v;

	double a = n/(p*1e9);
	double b = pow(log2(n), sqrt(2));
	double d = s/v;

	double lo = 1e-7, hi = 1e15, mi;
	while(lo + EPS < hi) {
		mi = (lo + hi) / 2;

		if (g(a, b, mi, d) > 0) hi = mi;
		else lo = mi;
	}

	cout << setprecision(10) << fixed << f(a, b, lo, d) << " " << lo << '\n';



	return 0;
}