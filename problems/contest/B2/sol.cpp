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

void compress(vector<int>& a, int& n) {
	vector<int> b;
	for (int i : a) {
		if (b.empty() || i != b.back()) b.push_back(i);
	}
	a = b;
	n = a.size();
}

inline void run_test(int test_number) {
	int n; rd(n);
	vector<int> c(n);
	for (int i = 0; i < n; i++) rd(c[i]);
	compress(c, n);

	vector<vector<int>> pos(n + 1);
	for (int i = 0; i < n; i++) pos[c[i]].push_back(i);

	vector<int> memo(n + 1);

	for (int i = n-1; i >= 0; i--) {
		memo[i] = memo[i + 1] + 1;
		auto it = upper_bound(pos[c[i]].begin(), pos[c[i]].end(), i);
		if (it != pos[c[i]].end()) memo[i] = min(memo[i], *it - i - 1 + memo[*it]);
	}

	print(memo[0]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}