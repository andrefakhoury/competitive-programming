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
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int n;

struct Query {
	vector<int> index;
	vector<int> answer;
	Query(vector<int> const& a, vector<int> const& b) : index(a), answer(b) {}
};

vector<Query> queries;

void ask(vector<int> x) {
	if (x.empty()) return;
	cout << x.size() << endl;
	for (int i : x) cout << i << " ";
	cout << endl;

	vector<int> ans(n);
	for (int& i : ans) cin >> i;

	queries.emplace_back(x, ans);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;

	for (int b = 0; b < 10; b++) {
		int sz = 1 << b;
		vector<int> id[2];
		for (int i = 0; i < n; i++) {
			if ((i / sz) % 2 == 0) id[0].pb(i + 1);
			else id[1].pb(i + 1);
		}
		ask(id[0]);
		ask(id[1]);
	}

	cout << -1 << endl;

	for (int i = 1; i <= n; i++) {
		int ans = INT_MAX;
		for (Query const& q : queries) if (!binary_search(q.index.begin(), q.index.end(), i)) {
			ans = min(ans, q.answer[i-1]);
		}
		cout << ans << " ";
	}

	cout << endl;
}
