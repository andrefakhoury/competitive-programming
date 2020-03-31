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

inline bool is_prime(int n) {
	for (int i = 2; i*i <= n; i++) if (n%i == 0)
		return false;
	return true;
}


vector<int> primes;
inline void _solve_() {
	int n; rd(n);
	vector<int> a(n);
	vector<int> c(n);

	for (int i = 0; i < n; i++) rd(a[i]);

	int cnt = 0;
	for (int p : primes) {
		bool used = false;
		cnt++;
		for (int i = 0; i < n; i++) {
			if (c[i]) continue;
			if (a[i]%p == 0) {
				c[i] = cnt;
				used = true;
			}
		}
		if (!used) cnt--;
	}

	printf("%d\n", cnt);
	for (int i = 0; i < n; i++) {
		printf("%d ", c[i]);
	}
	printf("\n");
}

int main() {
	for (int i = 2; i <= 1000; i++)
		if (is_prime(i)) primes.pb(i);
	int __T__; rd(__T__);
	while(__T__--) _solve_();
	return 0;
}