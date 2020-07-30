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
#ifndef __linux
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

inline void print(__int128 t) {
	string res = "";
	while(t) {
		int x = t%10;
		res += x + '0';
		t /= 10;
	}
	reverse(res.begin(), res.end());
	printf("%s", res.c_str());
}

inline __int128 get_positive(__int128 a, __int128 b) {
	__int128 lo = 0, hi = 1e9, mi;
	while(lo < hi) {
		mi = (lo + hi) / 2;
		__int128 k = b + 1 + mi * b;
		__int128 n = (b * k * k + b * k) / (2 * b);
		n -= (k-1) * a / b;
		if (n > 0) hi = mi;
		else lo = mi + 1;
	}

	return b + 1 + hi * b;
}

inline void _solve_(int __ntest__) {
	__int128 a, b; rd(a, b);

	vector<pair<__int128, __int128>> ans;

	for (__int128 k = get_positive(a, b);; k += b) {
		__int128 n = (b * k * k + b * k) / (2 * b);
		n -= (k-1) * a / b;
		if (n > k) break;
		ans.emplace_back(k, n);
	}

	printf("%ld\n", ans.size());
	for (auto p : ans) {
		print(p.fi);
		printf(" ");
		print(p.se);
		printf("\n");
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}