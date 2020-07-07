#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;
inline void _solve_(int __ntest__) {
	int n; rd(n);
	vector<int> a(n);
	for (auto& i : a) rd(i);

	auto get_mex = [&]() {
		set<int> all;
		for (int i = 0; i <= n; i++) all.insert(i);
		for (int i : a) all.erase(i);
		return *all.begin();
	};

	vector<int> ans;
	for (int i = 0; !is_sorted(a.begin(), a.end()); i++) {
		if (a[i] == i) continue;

		int mx = get_mex();
		printf("%d -> %d\n", i, mx);
		for (int i : a) printf("%d ", i);
		printf("\n");

		if (mx != i) {
			for (int j = i+1; j < n; j++) {
				if (a[j] == i) {
					ans.push_back(j+1);
					a[j] = mx;
					i--;
					break;
				}
			}

			// if (!ok) {
			// 	for (int j = 0; j < n; j++) {
			// 		if (a[j] >= i) {
			// 			ans.push_back(j+1);
			// 			ok = true;
			// 			a[j] = mx;
			// 			break;
			// 		}
			// 	}
			// }
		} else if (a[mx] != mx) {
			a[mx] = mx;
			ans.push_back(mx+1);
		}
	}

	// printf(">>>>>>");
	// for (int i : a) printf("%d ", i);
	// printf("\n");

	printf("%ld\n", ans.size());
	for (int i : ans) printf("%d ", i);
	printf("\n");

	assert((int) ans.size() <= n + n);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}