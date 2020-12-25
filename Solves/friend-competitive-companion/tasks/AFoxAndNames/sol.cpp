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

vector<int> edges[30];

int vis[MAXN];
vector<int> order;
bool ans;

void dfs(int u) {
	vis[u] = 1;
	for (int v : edges[u]) {
		if (vis[v] == 1) ans = false;
		else if (!vis[v]) dfs(v);
	}
	order.pb(u);
	vis[u] = 2;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	ans = true;
	for (int i = 1; i < n; i++) {
		// add restrictions a[i-1] < a[i]
		string& s = a[i-1];
		string& t = a[i]; // s <= t

		bool diff = false;
		for (int c = 0; c < (int) min(s.size(), t.size()); c++) {
			if (s[c] != t[c]) {
				edges[s[c]-'a'].pb(t[c]-'a');
				diff = true;
				break;
			}
		}

		if (!diff && s.size() > t.size()) {
			ans = false;
		}
	}

	for (int c = 0; c < 26; c++) {
		if (!vis[c]) dfs(c);
	}

	if (ans) {
		reverse(order.begin(), order.end());
		for (int c : order) cout << char(c+'a');
		cout << "\n";
	} else cout << "Impossible\n";
}
