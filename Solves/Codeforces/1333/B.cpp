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
	int n; rd(n);
	vector<int> a(n), b(n);
	for (int& i : a) rd(i);
	for (int& i : b) rd(i);

	map<int, int> f;
	for (int i : a) f[i]++;

	bool ans = true;
	for (int i = n-1; ans && ~i; i--) {
		f[a[i]]--;

		// tem algum cara atras de mim que pode fazer a boa?
		if (a[i] < b[i]) { // preciso aumentar
			if (f[1]) continue;
			else ans = false;
		} else if (a[i] > b[i]) {
			if (f[-1]) continue;
			else ans = false;
		}
	}

	printf("%s\n", ans ? "YES" : "NO");


}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	while(__T__--) _solve_();
	return 0;
}