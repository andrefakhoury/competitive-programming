#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) cout.flush(); fflush(stdout); fprintf(stderr, args)
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
	x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

const int MOD = 11092019;

inline int mul(int x, int y) {
	return ll(x) * y % MOD;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s; cin >> s;

	map<char, int> f;
	for (char c : s) f[c]++;

	int ans = 1;
	for (auto p : f) {
		ans = mul(ans, p.se+1);
	}

	printf("%d\n", ans);

	
}