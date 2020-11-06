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
#ifdef _WIN32
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

int main() {
	int n; rd(n);
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) rd(a[i]);
	vector<vector<ll>> maxi(n + 2, vector<ll>(n + 2));
	vector<vector<ll>> mini(n + 2, vector<ll>(n + 2));

	for (int sz = 1; sz <= n; sz++) {
		for (int l = 1; l + sz - 1 <= n; l++) {
			int r = l + sz - 1;
			maxi[l][r] = max(a[l] + mini[l+1][r], a[r] + mini[l][r-1]);
			mini[l][r] = min(maxi[l+1][r], maxi[l][r-1]);
		}
	}

	printf("%lld\n", maxi[1][n]);
}