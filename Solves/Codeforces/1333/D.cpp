#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) cout.flush(); fflush(stdout); fprintf(stderr, args)
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
	x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

inline void imp() {
	cout << -1 << "\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	string s; cin >> s;

	int qttR = 0, qttL = 0;
	for (int i = 0; i < n; i++) qttR += s[i] == 'R';

	vector<int> final(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') final[i] = n - qttR, qttR--;
		else final[i] = qttL++;
		if (abs(final[i] - i) > k) imp();
	}

	vector<vector<int>> changes(k);

	vector<int> L(n+5), R(n+5);
	vector<pii> st[2];

	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') R[i] = 1;
		if (s[i] == 'L') L[i] = 1;
		if (i < n-1 && s[i] == 'R' && s[i+1] == 'L') st[0].eb(i, i+1);
	}

	int mxi = 0;
	for (int day = 0; day < k; day++) {
		if (st[day&1].empty()) break;
		mxi = day + 1;

		for (auto p : st[day&1]) {
			changes[day].eb(p.se);
			L[p.se] = R[p.fi] = 0;
			L[p.fi] = R[p.se] = 1;
			if (p.se < n && L[p.se+1]) st[(day+1)&1].eb(p.se, p.se+1);
			if (p.fi > 0 && R[p.fi-1]) st[(day+1)&1].eb(p.fi-1, p.fi);
		}

		st[day&1].clear();
	}

	if (st[k&1].size()) imp();

	int curDay = -1;
	vector<vector<int>> ans(k);
	for (int i = 0; i < k; i++) {
		sort(changes[i].begin(), changes[i].end());
		changes[i].erase(unique(changes[i].begin(), changes[i].end()), changes[i].end());

		curDay++;
		for (int j : changes[i]) {
			ans[curDay].eb(j);
			if (mxi < k && j != changes[i].back()) {
				mxi++;
				curDay++;
			}
		}
	}

	if (ans[k-1].empty()) imp();
	assert(mxi == k);

	for (int i = 0; i < k; i++) {
		cout << ans[i].size() << " ";
		for (int j : ans[i]) cout << j << " ";
		cout << "\n";
	}
}