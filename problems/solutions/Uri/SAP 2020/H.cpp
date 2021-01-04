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

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
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

const int MAXN = 2e4 + 5, INF = 0x3f3f3f3f;
const int MAXM = 1e3 + 5;

int n;
map<char, string> mp;
string M, T;

bool vis[MAXN][MAXM][2];

inline void yes() {
	cout << "Yes" << endl;
	exit(0);
}

// <pos, dif>
void solve(int i, int j, int dif) {
	if (i == (int) T.size()) {
		if (dif) yes();
		return;
	}

	if (vis[i][j][dif]) return;
	vis[i][j][dif] = true;

	for (auto p : mp) {
		bool ok = true;
		// verifica se T[i..len] = p.se
		int len = p.se.size();
		if ((int) T.size() - i < len) ok = false;
		else {
			// cout << T.substr(i, len) << " vs " << p.se << endl;;
			ok = T.substr(i, len) == p.se;
		}

		if (ok) {
			if (!dif && M[j] == p.fi) solve(i+len, j+1, 0);
			else solve(i+len, 0, 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		char c; cin >> c;
		mp[c] = s;
	}

	cin >> M;
	for (char c : M) T += mp[c];

	solve(0, 0, 0);
	cout << "No" << endl;
}