/*
ID: fakhoury
LANG: C++14
TASK: tracing
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

const int MAXN = 100 + 5, MAXT = 250 + 5, INF = 0x3f3f3f3f;

char aux[MAXN];

struct Event {
	int t, u, v;

	inline void read() {
		rd(t, u, v);
	}
};

bool inf[MAXN];

bool curInfected[MAXN];
int qttLeft[MAXN];
inline bool check(int i, int k, vector<Event>& a, int n) {
	memset(curInfected, 0, sizeof curInfected);
	memset(qttLeft, 0, sizeof qttLeft);

	curInfected[i] = true;
	qttLeft[i] = k;

	for (Event& ev : a) {
		bool infU = false, infV = false;

		if (qttLeft[ev.u]) {
			qttLeft[ev.u]--;
			infV = true;
		}

		if (qttLeft[ev.v]) {
			qttLeft[ev.v]--;
			infU = true;
		}

		if (infU && !curInfected[ev.u]) {
			curInfected[ev.u] = true;
			qttLeft[ev.u] = k;
		}

		if (infV && !curInfected[ev.v]) {
			curInfected[ev.v] = true;
			qttLeft[ev.v] = k;
		}
	}

	bool ok = true;
	for (int i = 1; i <= n; i++)
		ok &= curInfected[i] == inf[i];

	return ok;
}

int main() {
#ifndef LOCAL_PC
	freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
#endif

	int n, t; rd(n, t);
	scanf(" %s", aux+1);

	for (int i = 1; i <= n; i++) inf[i] = aux[i] == '1';

	vector<Event> a(t);
	for (Event& e : a) e.read();

	sort(a.begin(), a.end(), [&](Event const& x, Event const& y) {
		return x.t < y.t;
	});

	int ans = 0, mnK = INF, mxK = 0;
	for (int i = 1; i <= n; i++) {
		if (!inf[i]) continue;

		pii curK = {INF, 0};
		for (int k = 0; k <= 500; k++) {
			if (check(i, k, a, n)) {
				curK.fi = min(curK.fi, k);
				curK.se = max(curK.se, k);
			}
		}

		ans += curK.fi != INF;
		mnK = min(mnK, curK.fi);
		mxK = max(mxK, curK.se);
	}

	printf("%d %d ", ans, mnK);
	if (mxK == 500) printf("Infinity\n");
	else printf("%d\n", mxK);

	return 0;
}