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

template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;

	map<string, int> last;
	map<string, int> xp;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int m; cin >> m;

		if (!last.count(s) || last[s] + k <= m) {
			last[s] = m;
			xp[s] += 25;
		}
	}

	vector<pair<string, int>> vec;
	for (auto xx : xp) {
		vec.eb(xx.fi, xx.se);
	}

	sort(vec.begin(), vec.end(), [&](pair<string, int>& a, pair<string, int>& b) {
		return a.se == b.se ? a.fi < b.fi : a.se > b.se;
	});

	cout << "--Rank do Nepscord--\n";

	int N = vec.size();
	for (int i = 0; i < min(3, N); i++) {
		cout << "#" << i+1 << ". " << vec[i].fi << " - Nivel " << (vec[i].se/100 + 1) << "\n";
	}
	for (int i = N; i < 3; i++) {
		cout << "#" << i+1 << ".\n";
	}
}