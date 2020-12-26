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

inline void print(__int128 x) {
	string s;
	while(x) {
		s += x % 10 + '0';
		x /= 10;
	}
	reverse(s.begin(), s.end());
	cout << s << "\n";
}

int main() {
	int T; rd(T);

	int cnt = 0;
	__int128 ans = 0;
	while(T--) {
		int n; rd(n);
		vector<__int128> X(n), Y(n);
		for (int i = 0; i < n; i++) {
			rd(X[i], Y[i]);
		}

		__int128 curArea = 0;
		for (int i = 0, j = n-1; i < n; i++) {
			curArea += (X[j] + X[i]) * (Y[j] - Y[i]);
			j = i;
		}
		curArea = curArea > 0 ? curArea : -curArea;
		ans += curArea/2;
		cnt += curArea % 2;
	}

	ans += cnt/2;
	print(ans);	
}