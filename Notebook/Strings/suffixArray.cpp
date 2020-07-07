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

const int MAXN = 1e6 + 5, INF = 0x3f3f3f3f;

int pos[2 * MAXN][21];
tuple<int, int, int> vals[MAXN];

vector<int> suffix_array(string const& s) {
	int n = s.size();

	for (int i = 0; i < n; i++) pos[i][0] = pos[i+n+1][0] = s[i] - 'a' + 1;
	pos[n][0] = pos[n+n+1][0] = 0;
	
	for (int k = 1; k < 21; k++) {
		for (int i = 0; i <= n; i++)
			vals[i] = {pos[i][k-1], pos[i+(1<<(k-1))][k-1], i};
		sort(vals, vals+n+1);
		pos[get<2>(vals[0])][k] = 0;
		pair<int, int> last = {0, 0};
		for (int i = 1, l = 1; i <= n; i++) {
			auto [vl, vr, id] = vals[i];
			if (mk(vl, vr) == last) pos[id][k] = l;
			else pos[id][k] = ++l;
			last = {vl, vr};
		}
	}

	vector<int> ret;
	for (int i = 0; i <= n; i++) ret.emplace_back(get<2>(vals[i]));
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s; cin >> s;
	vector<int> ans = suffix_array(s);

	for (int i : ans) cout << i << " ";
	cout << "\n";
}