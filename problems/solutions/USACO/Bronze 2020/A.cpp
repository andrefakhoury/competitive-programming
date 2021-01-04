/*
ID: fakhoury
LANG: C++14
TASK: socdist1
*/

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

inline bool ok(vector<int>& pos, int d, int i) {
	int val = *upper_bound(pos.begin(), pos.end(), i);
	return val - i >= d;
}

vector<int> pos;
inline bool check(string& s, int d) {
	int qtt = 2;

	int last = -s.size();
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '1') {
			if (i - last < d) return false;
			last = i;
		}
		else {
			if (i - last >= d && ok(pos, d, i)) {
				last = i;
				qtt--;
			}
		}
	}

	return qtt <= 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

#ifndef LOCAL_PC
	freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
#endif

	int n; cin >> n;
	string s; cin >> s;

	for (int i = 0; i < (int)s.size(); i++)
		if (s[i] == '1') pos.eb(i);
	pos.eb(INF);

	int lo = 0, hi = INF, mi;
	while(lo < hi) {
		mi = (lo + hi + 1) / 2;
		if (check(s, mi)) lo = mi;
		else hi = mi - 1;
	}

	cout << lo << endl;
}