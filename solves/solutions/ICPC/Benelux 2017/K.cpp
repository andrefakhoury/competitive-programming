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

const int MAXN = 1e3 + 5, INF = 0x3f3f3f3f;

vector<int> edges[MAXN];
int level[MAXN];

string s[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			if (s[i][j] == '1') {
				edges[i].eb(j);
			}
		}
	}

	queue<int> q;
	q.emplace(0);
	level[0] = 1;

	vector<pii> ord;

	while(q.size()) {
		int u = q.front();
		q.pop();

		ord.eb(-level[u], u);

		for (int v : edges[u]) {
			if (!level[v]) {
				level[v] = level[u] + 1;
				q.emplace(v);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (level[i] == 0) {
			cout << "impossible\n";
			return 0;
		}
	}

	sort(ord.begin(), ord.end());

	int best = ord[0].se;
	for (int i = 1; i < n-1; i++) {
		if (s[ord[i].se][best] == '1')
			best = ord[i].se;
	}

	if (s[0][best] != '0') {
		for (auto [x, i] : ord)
			cout << i << " ";
		cout << "\n";
	} else {
		cout << "impossible\n";
	}
}