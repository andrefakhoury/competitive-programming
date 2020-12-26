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

inline void print(vector<int>& a) {
	for (int x : a) printf("%d ", x);
	printf("\n");
}

int main() {
	int n; rd(n);
	if (n == 1) return !printf("1\n");

	vector<vector<int>> ans;

	ans.eb(vector<int>(1));
	ans.back().back() = 1;

	for (int d = 2; d <= n; d++) {
		vector<vector<int>> nxt;

		int poss = 0;
		for (auto p : ans) {
			poss++;
			vector<vector<int>> cur;
			for (int i = 0; i <= (int)p.size(); i++) {
				vector<int> aux = p;
				aux.insert(aux.begin() + i, d);
				cur.eb(aux);
			}

			if (poss%2 == 1) reverse(cur.begin(), cur.end());
			for (auto p : cur) nxt.eb(p);
		}

		ans = nxt;
	}

	for (auto p : ans) print(p);
}