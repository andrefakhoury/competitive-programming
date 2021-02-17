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

using pli = pair<ll, int>;
inline void run_test(int test_number) {
	int n; rd(n);
	vector<pli> a(n);
	for (int i = 0; i < n; i++) {
		rd(a[i].fi);
		a[i].se = i;
	}
	sort(a.begin(), a.end());

	ll sum = 0;

	vector<int> can(n);
	for (int i = 0; i < n; i++) {
		sum += a[i].fi;
		can[i] = i + 1 == n || sum >= a[i + 1].fi;
	}

	vector<int> suf(n);
	for (int i = n-1; i >= 0; i--) {
		suf[i] = can[i];
		if (i + 1 < n) suf[i] &= suf[i + 1];
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (suf[i]) ans.pb(a[i].se);
	}

	sort(ans.begin(), ans.end());
	print(ans.size());
	for (int i : ans) cout << i + 1 << " ";
	cout << "\n";
}

int main() {

//#ifndef LOCAL_PC
//	freopen("FILE.in", "r", stdin);
//#endif

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	rd(n_tests);
	for (int i = 1; i <= n_tests; i++) run_test(i);
}