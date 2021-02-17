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

ll solve(ll n, ll k) {
	ll ans = -1;

	if (n % 2 == 0) {
		k--;
		ans = 1 + (k % n);
	} else {
		k--;
		ll turns = k / n;
		ll expected = k % n;

		ll szCycle = n / 2;
		ll turn2 = turns == 0 ? 0 : 1 + turns - (turns + szCycle - 1) / szCycle;
		ll turn3 = turns == 0 ? 0 : (turns + szCycle - 1) / szCycle - 1;
		expected += 2 * turn2;
		expected += 3 * turn3;

		set<int> pos;
		pos.insert(((n - 1 - turns) % n + n) % n);
		pos.insert(((n/2 - turns) % n + n) % n);
		if (turns > 0 && turns % szCycle == 0) pos.insert(0), pos.insert(n - 1), pos.insert(n/2);
		for (int p : pos) expected += k % n >= p;

		ans = 1 + expected % n;
	}
	return ans;
}

void brute(ll n) {
	auto nx = [n](ll p) {
		return p % n + 1;
	};
	auto pv = [n](ll p) {
		return p - 1 == 0 ? n : p - 1;
	};

	for (int pos = 1, ot = n, turn = 0; turn <= 100; turn++) {
		print(turn % n + 1, pos);
		pos = nx(pos);
		ot = pv(ot);
		if (pos == ot) pos = nx(pos);
	}
}

int main() {

//#ifndef LOCAL_PC
//	freopen("FILE.in", "r", stdin);
//#endif

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	rd(n_tests);
	brute(n_tests);
}