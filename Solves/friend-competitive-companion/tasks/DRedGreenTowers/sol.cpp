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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

using uint = unsigned int;
const int M2 = 300007;

inline int get(const uint a, const uint b) {
	return (1ll * a + b * M2) % M2;
}

uint solve(uint r, uint g, uint h) {
	vector<uint> old(M2), act(M2, 1);
	for (int i = 1; i <= h; i++) {

	}



}

//
//uint mp[900][M2];
////unordered_map<int, uint> mp[900];
//uint solve(uint r, uint g, uint n) {
//	if (n == 0) return 1;
//	if (r > g) swap(r, g);
//
//	uint& ret = mp[n][get(r, g)];
//	if (ret) return ret;
//	if (r >= n) ret += solve(r - n, g, n - 1);
//	if (g >= n) ret += solve(r, g - n, n - 1);
//	while (ret >= MOD) ret -= MOD;
//	return ret;
//}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int r, g; cin >> r >> g;
	int h = 1;
	while((h + 1) * (h + 2) / 2 <= r + g) h++;
	cout << solve(r, g, h) << "\n";
}