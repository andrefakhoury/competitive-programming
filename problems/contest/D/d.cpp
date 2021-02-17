#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) print(__VA_ARGS__), print('\n')

inline void run_test(int test_number) {
	int n; rd(n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) rd(a[i]);
	sort(a.rbegin(), a.rend());
	// qts vezes o segundo pirata pegou um bau maior que ele em rodadas anteriores

	vector<vector<double>> p(n, vector<double>(n));
	vector<double> s(n); // prob do primeiro cara pegar i
	for (int i = 0; i < n; i++) {
		double cur_sum = 0;
		for (int j = 0; j < i; j++) {
			int left = n - 2 * j - 1;
			if (left > 0) p[i][j] = (1.0 - cur_sum) * (1.0 / left);
			cur_sum += p[i][j];
		}
		s[i] = 1.0 - cur_sum;
	}

	double ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++) {
		ans1 += s[i] * a[i];
		ans2 += (1.0 - s[i]) * a[i];
	}

	cout << fixed << setprecision(15);
	print(ans1, ans2);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}