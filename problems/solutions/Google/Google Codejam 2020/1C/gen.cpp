#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) { cout.flush(); fflush(stdout); fprintf(stderr, args); }
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

void print(__int128 x) {
	string ans;
	while(x) {
		ans += (x % 10) + '0';
		x /= 10;
	}

	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}

int main() {
	int fac[20] = {0};

	for (int i = 2; i <= 20; i++) {
		int cur[20] = {0};

		int I = i;
		printf("%d: ", i);

		for (int j = 2; j * j <= I; j++) {
			while (i%j == 0) {
				cur[j]++;
				printf("%d ", j);
				i /= j;
			}
		}

		for (int k = 0; k < 20; k++) fac[k] = max(fac[k], cur[k]);

		if (i) printf("%d ", i);
		fac[i]++;
		i = I;
		printf("\n");
	}

	__int128 ans = 1;

	for (int i = 0; i < 20; i++) {
		printf("%d ", fac[i]);
		while(fac[i]) {
			ans *= i;
			fac[i]--;
		}
	}

	print(ans);


	printf("\n");
}