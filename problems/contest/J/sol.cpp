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

int n;
string _s;

ll solve3(char a, int fa, char c) {
	string s = _s;

	int idb = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'b') idb = i;
	}

	ll ans = 0;
	if (idb != fa) {
		ans++;
		swap(s[idb], s[fa]);
	}

	int a_w = 0, c_w = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == a) {
			a_w += i >= fa;
		} else if (s[i] == c) {
			c_w += i <= fa;
		}
	}

	ans += a_w;
	return ans;
}

inline void run_test(int test_number) {
	rd(n, _s);

	string s = _s;

	int f[3] = {};
	for (char c : s) f[c-'a']++;

	ll ans = 0;
	if (f[0] && f[1] && f[2]) {
		ll a1 = solve3('a', f[0], 'c');
		ll a2 = solve3('c', f[2], 'a');
		ans = min(a1, a2);
	} else if (f[0] && f[2]) {
		ans = -1;
	} else {
		ans = 0;
	}

	print(ans);
}

int main() {

#ifndef LOCAL_PC
	freopen("abc.in", "r", stdin);
#endif

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}