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

const int MAXN = 1e5 + 1, INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<vector<int>> memo(n + 1, vector<int>(MAXN));
	memo[n][0] = 1;

	vector<int> ans;
	for (int x = 0; x < MAXN; x++) {
		for (int i = n-1; i >= 0; i--) {
			memo[i][x] = memo[i+1][x];
			if (a[i] <= x) memo[i][x] |= memo[i+1][x - a[i]];
		}
		if (x && memo[0][x]) ans.pb(x);
	}

	cout << ans.size() << "\n";
	for (int x : ans) cout << x << " ";
	cout << "\n";
}