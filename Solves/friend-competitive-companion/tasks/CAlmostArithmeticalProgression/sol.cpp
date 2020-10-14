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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	vector<int> all;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		all.pb(a[i]);
	}

	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());

	int N = all.size();
	vector<vector<int>> pos(N);
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
		pos[a[i]].pb(i);
	}

	int ans = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			int cur = 0;
			for (int i = 0, j = 0, l = -1, c = x, d = y, nx = pos[x].size(), ny = pos[y].size(); i < nx; ) {
				if (pos[c][i] > l) {
					l = pos[c][i];
					cur++;
					i++;
					swap(i, j);
					swap(c, d);
					swap(nx, ny);
				} else {
					i++;
				}
			}

			ans = max(ans, cur);
		}
	}

	cout << ans << "\n";
}