#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl 
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
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	string s, t; cin >> s >> t;

	int f[26] = {};
	for (int i = 0; i < n; i++) f[s[i]-'a']++;
	for (int i = 0; i < n; i++) f[t[i]-'a']++;
	for (int i = 0; i < 26; i++) {
		if (f[i] % 2) {
			cout << -1 << "\n";
			return 0;
		}
	}

	set<int> pos[26][26][2];
	for (int i = 0; i < n; i++) if (s[i] != t[i]) {
		pos[s[i]-'a'][t[i]-'a'][0].insert(i);
		pos[t[i]-'a'][s[i]-'a'][1].insert(i);
	}

	// procura em T um igual a S
	auto getBestT = [&](int nT, int cT, int nS, int cS)->int {
		bool can = pos[cT][cS][nT].size() > 1u;
		if (can) return *pos[cT][cS][nT].rbegin();
		for (int i = 0; i < 26; i++) if (i != cS) {
			if (pos[cT][i][nT].size()) return *pos[cT][i][nT].begin();
		}
		cout << -1 << endl;
		exit(0);
	};

	vector<pii> ans;
	for (int i = 0; i < n; i++) if (s[i] != t[i]) {
		int c1 = 0, c2 = 0;
		for (int j = 0; j < 26; j++) {
			c1 += pos[t[i]-'a'][j][1].size();
			c2 += pos[s[i]-'a'][j][0].size();
		}

		if (c1 > 1) {
			int j = getBestT(1, t[i]-'a', 0, s[i]-'a');

			pos[t[i]-'a'][s[j]-'a'][1].erase(j);
			pos[s[i]-'a'][s[j]-'a'][1].insert(j);

			ans.eb(i+1, j+1);

			pos[s[i]-'a'][t[i]-'a'][0].erase(i);
			pos[t[i]-'a'][s[i]-'a'][1].erase(i);
			swap(s[i], t[j]);
		} else if (c2 > 1) {
			int j = getBestT(0, s[i]-'a', 1, t[i]-'a');

			pos[s[i]-'a'][t[j]-'a'][0].erase(j);
			pos[t[i]-'a'][t[j]-'a'][0].insert(j);

			ans.eb(j+1, i+1);
			pos[s[i]-'a'][t[i]-'a'][0].erase(i);
			pos[t[i]-'a'][s[j]-'a'][1].erase(i);

			swap(t[i], s[j]);
		} else {
			pos[s[i]-'a'][t[i]-'a'][0].erase(i);
			pos[t[i]-'a'][s[i]-'a'][1].erase(i);
			ans.eb(i+1, i+1);
			swap(s[i], t[i]);
			pos[s[i]-'a'][t[i]-'a'][0].insert(i);
			pos[t[i]-'a'][s[i]-'a'][1].insert(i);
			i--;
		}
	}

	cout << ans.size() << "\n";
	for (pii p : ans) cout << p.fi << " " << p.se << "\n";
}
