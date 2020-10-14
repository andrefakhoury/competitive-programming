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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m, t; cin >> n >> m >> t;

	vector<__int128> fac(31);
	fac[0] = 1;
	for (int i = 1; i <= 30; i++)
		fac[i] = fac[i-1] * i;

	auto nck = [&](int n, int k) {
		return fac[n] / fac[k] / fac[n-k];
	};

	__int128 ans = 0;
	for (int qm = 4; qm <= n; qm++) {
		for (int qf = 1; qf <= m; qf++) {
			if (qm + qf != t) continue;
			ans += nck(n, qm) * nck(m, qf);
		}
	}

	auto tostring = [](__int128 x) {
		string ans;
		while(x) ans += (x % 10) + '0', x /= 10;
		reverse(ans.begin(), ans.end());
		return ans;
	};

	cout << tostring(ans) << "\n";
}