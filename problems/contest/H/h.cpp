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

inline void run_test() {
	ll A, B; rd(A, B);

	ll ans = -1;
	for (ll i = A; i <= B; i++) {
		string s = to_string(i);

		string s1 = s.substr(0, s.size()/2);
		string s2 = s.substr(s.size()/2);
		ll d1 = stoll(s1), d2 = stoll(s2);
		DBG(d1, d2, gcd(d1, d2));
		if (d2 > 0 && gcd(d1, d2) > 1) {
			ans = i;
		}
	}

	if (ans == -1) print("impossible");
	else print(ans);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

#ifndef LOCAL_PC
	freopen("halfnice.in", "r", stdin);
#endif

	int T; rd(T);
	for (int cs = 1; cs <= T; cs++) {
		cout << "Case " << cs << ": ";
		run_test();
	}
}