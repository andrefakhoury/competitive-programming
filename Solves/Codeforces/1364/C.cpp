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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int a[MAXN];

inline void imp() {
	puts("-1");
	exit(0);
}

int ans[MAXN];

int main() {
	int n; rd(n);
	for (int i = 1; i <= n; i++) rd(a[i]);

	vector<int> disp = {};
	set<int> cur = {-1};
	mset(ans, -1);

	for (int i = 1; i <= n; i++) {
		auto get_mex = [&]() {
			while(cur.size() > 1u) {
				int fi = *cur.begin();
				cur.erase(fi);
				int se = *cur.begin();
				cur.erase(fi);
				if (fi+1 != se) {
					cur.emplace(fi);
					cur.emplace(se);
					break;
				} else {
					cur.emplace(se);
				}
			}

			return 1 + *cur.begin();
		};

		int mex = get_mex();

		if (a[i] == mex) disp.eb(i);
		else if (a[i] < mex) imp();
		else {
			disp.eb(i);
			for (int j = disp.size()-1, k = get_mex(); k < a[i] && j >= 0; j--, k = get_mex()) {
				ans[disp[j]] = k;
				cur.emplace(k);
				disp.pop_back();
			}

			if (a[i] != get_mex()) imp();
		}
	}

	for (int i = 1; i <= n; i++) {
		if (ans[i] == -1) ans[i] = n+1;
	}

	{
		set<int> cur = {-1};
		for (int i = 1; i <= n; i++) {
			auto get_mex = [&]() {
				while(cur.size() > 1u) {
					int fi = *cur.begin();
					cur.erase(fi);
					int se = *cur.begin();
					cur.erase(fi);
					if (fi+1 != se) {
						cur.emplace(fi);
						cur.emplace(se);
						break;
					} else {
						cur.emplace(se);
					}
				}

				return 1 + *cur.begin();
			};
			cur.emplace(ans[i]);
			if (get_mex() != a[i]) {
				// assert(0);
				imp();
			}
		}
	}



	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	printf("\n");
}