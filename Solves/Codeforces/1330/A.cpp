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

inline void _solve_() {
	int n, x; rd(n, x);
	vector<int> a(n);
	for (auto& i : a) rd(i);

    set<int> all;
	for (int i = 0; i < n; i++) {
		all.emplace(a[i]);
	}

	int last = 0, ans = 0;
	for (int i : all) {
		if (i - last - 1 <= x) {
			x -= i - last - 1;
			last = i;
		} else {
			last += x;
			x = 0;
			break;
		}
	}

	cout << last + x << "\n";


}

int main() {
	int __T__; rd(__T__);
	while(__T__--) _solve_();
	return 0;
}