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
	char c, neg = 0; while(isspace(c = getchar()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

inline void isolve() {
	int n; rd(n);

	vector<ll> all; all.reserve(n+n+n);
	vector<pair<ll, ll>> a(n);
	for (int i = 0; i < n; i++) {
		rd(a[i].fi, a[i].se);
		all.pb(a[i].fi);
		all.pb(a[i].fi - a[i].se);
		all.pb(a[i].fi + a[i].se);
	}

	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	auto getpos = [&](ll k)->int {
		return lower_bound(all.begin(), all.end(), k) - all.begin();
	};

	int N = all.size();
	vector<vector<tuple<int, int, ll>>> pos(N);
	for (int i = 0; i < n; i++) {
		pos[getpos(a[i].fi)].emplace_back(i, getpos(a[i].fi + a[i].se), a[i].se);
		pos[getpos(a[i].fi - a[i].se)].emplace_back(i, getpos(a[i].fi), a[i].se);
	}

	for (int i = 0; i < N; i++)
		sort(pos[i].begin(), pos[i].end());

	vector<vector<ll>> memo[3];

	for (int j = 0; j < 3; j++) {
		memo[j].resize(N);
		for (int i = 0; i < N; i++) 
			memo[j][i].resize(pos[i].size());
	}
	
	ll answer = 0;
	for (int i = N-1; ~i; i--) {
		int m = pos[i].size();

		for (int j = 0; j < m; j++) {
			auto [idx, nxt, profit] = pos[i][j];

			int nxt_id = lower_bound(pos[nxt].begin(), pos[nxt].end(), make_tuple(idx, 0, 0ll)) - pos[nxt].begin();
			if (nxt_id != (int) pos[nxt].size() && get<0>(pos[nxt][nxt_id]) == idx) {
				if (nxt_id) memo[0][i][j] = max(memo[0][i][j], memo[1][nxt][nxt_id-1]);
				if (nxt_id+1 < (int) pos[nxt].size()) memo[0][i][j] = max(memo[0][i][j], memo[2][nxt][nxt_id+1]);
			} else {
				if (pos[nxt].size()) memo[0][i][j] = max(memo[0][i][j], memo[2][nxt][0]);
			}

			memo[0][i][j] += profit;
			answer = max(answer, memo[0][i][j]);

			if (j) memo[1][i][j] = max(memo[1][i][j-1], memo[0][i][j]);
		}

		for (int j = m-1; ~j; j--)
			memo[2][i][j] = max(j != m-1 ? memo[2][i][j+1] : 0ll, memo[0][i][j]);
	}

	printf("%lld\n", answer);
}

int main() {
	int T; rd(T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		isolve();
	}
}