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

const int MAXN = 100, INF = 0x3f3f3f3f;

#define hash uasuhadia

vector<pair<pair<pii, int>, int>> starting[26]; // <{{hash}, reward}, size>
map<string, int> memo;

const int P[2] = {31, 37};
const int MOD[2] = {1'000'000'007, 1'000'000'009};
int power[MAXN][2];

inline int add(int x, int y, int k) {
	x += y;
	if (x >= MOD[k]) x -= MOD[k];
	return x;
}

inline int sub(int x, int y, int k) {
	x -= y;
	if (x < 0) x += MOD[k];
	return x;
}

inline int mul(int x, int y, int k) {
	return ll(x) * y % MOD[k];
}

string tira(string s, int i, int len) {
	s.erase(i, len);
	return s;
}

int solve(string s) {
	if (memo.count(s)) return memo[s];
	int ans = 0;

	int n = s.size();
	vector<pii> hash(n);

	for (int i = 0; i < n; i++) {
		hash[i].fi = add((i ? hash[i-1].fi : 0), mul(s[i]-'a'+1, power[i][0], 0), 0);
		hash[i].se = add((i ? hash[i-1].se : 0), mul(s[i]-'a'+1, power[i][1], 1), 1);
	}

	for (int i = 0; i < n; i++) {
		for (auto c : starting[s[i]-'a']) {
			if (i + c.se - 1 >= n) continue;
			int hashc[2] = {mul(c.fi.fi.fi, power[i][0], 0), mul(c.fi.fi.se, power[i][1], 1)};
			int hashs[2] = {sub(hash[i+c.se-1].fi, (i ? hash[i-1].fi : 0), 0), sub(hash[i+c.se-1].se, (i ? hash[i-1].se : 0), 1)};

			if (mk(hashc[0], hashc[1]) == mk(hashs[0], hashs[1]))
				ans = max(ans, c.fi.se + solve(tira(s, i, c.se)));
		}
	}

	return memo[s] = ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s; cin >> s;
	int n; cin >> n;

	power[0][0] = power[0][1] = 1;
	for (int i = 1; i < MAXN; i++) {
		for (int j = 0; j < 2; j++) {
			power[i][j] = mul(power[i-1][j], P[j], j);
		}
	}

	for (int i = 0; i < n; i++) {
		string t; cin >> t;
		int reward; cin >> reward;

		int hash[2] = {};
		for (int j = 0; j < (int) t.size(); j++) {
			for (int k = 0; k < 2; k++) {
				hash[k] = add(hash[k], mul(t[j]-'a'+1, power[j][k], k), k);
			}
		}

		starting[t[0]-'a'].emplace_back(mk(mk(hash[0], hash[1]), reward), t.size());

		reverse(t.begin(), t.end());


		hash[0] = hash[1] = 0;
		for (int j = 0; j < (int) t.size(); j++) {
			for (int k = 0; k < 2; k++) {
				hash[k] = add(hash[k], mul(t[j]-'a'+1, power[j][k], k), k);
			}
		}

		starting[t[0]-'a'].emplace_back(mk(mk(hash[0], hash[1]), reward), t.size());
	}

	cout << solve(s) << "\n";
}