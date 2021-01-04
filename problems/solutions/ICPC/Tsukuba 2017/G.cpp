#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cerr << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

const int MAXN = 3e5 + 5, INF = 0x3f3f3f3f;

const double PI = acos(-1.0);

string face() {
	string ed;
	int d, l;
	cin >> ed >> d >> l;

	double x = l * sin(PI/2 - d * PI / 180);
	double y = l * sin(d * PI / 180);

	char A = 'A';
	char B = ed[0];
	char C = ed[1];
	char D = 'A'^'B'^'C'^'D'^A^B^C;

	int N = 90;
	vector<tuple<double, double, char>> points;
	for (int row = 0; row < N; row++) {
		double j = row * sqrt(3) / 2;
		if (row%2 == 0) {
			for (int col = row / 2; col < N; col += 2) {
				double i = col;
				points.emplace_back(i+0, j, A);
				points.emplace_back(i+1, j, B);
			}
		} else {
			for (int col = row / 2; col < N; col += 2) {
				double i = col + 0.5;
				points.emplace_back(i, j, C);
				points.emplace_back(i+1, j, D);
			}
		}
	}

	auto dist = [&](double x1, double y1) {
		return (x - x1) * (x - x1) + (y - y1) * (y - y1);
	};

	sort(points.begin(), points.end(), [&](tuple<double, double, char> const& a, tuple<double, double, char> const& b) {
		return dist(get<0>(a), get<1>(a)) < dist(get<0>(b), get<1>(b));
	});

	string ans;
	for (int i = 0; i < 3; i++)
		ans += get<2>(points[i]);
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	string a = face();
	string b = face();
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a == b) cout << "YES\n";
	else cout << "NO\n";
}