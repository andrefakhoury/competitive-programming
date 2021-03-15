#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int N = 1000007, inf = 0x3f3f3f3f;

double r[N];
double x[N], y[N];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> r[i];
		y[i] = r[i];
	}

	x[0] = r[0];
	double ans = 2 * r[0];
	for(int i = 1; i < n; ++i) {
		// adiciona circulo i
		x[i] = r[i];
		for(int j = 0; j <= i - 1; ++j) {
			x[i] = max(x[i], x[j] + sqrt((r[i] + r[j]) * (r[i] + r[j]) - (y[i] - y[j])*(y[i] - y[j])));
		}
		ans = max(ans, x[i] + r[i]);
	}

	cout << fixed << setprecision(10) << ans << endl;
}