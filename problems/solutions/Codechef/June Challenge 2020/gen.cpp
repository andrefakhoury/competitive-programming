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

int main() {
	int T = 1;
	printf("%d\n", T);

	while(T--) {
		vector<int> a(3);
		vector<int> b(3);

		ll Mul = randint(-1000000000, 1000000000);
		ll Add = randint(-1000000000, 1000000000);

		for (int i = 0; i < 3; i++) a[i] = randint(-1000000000, 1000000000);
		for (int i = 0; i < 3; i++) {
			if (rng()%3 == 0) b[i] += randint(-1000000000, 1000000000);
			else if (rng()%2 == 0) b[i] *= randint(-1000000000, 1000000000);
			
			if (rng()%2 == 0) b[i] *= randint(-1000000000, 1000000000);
			else if (rng()%3 == 0) b[i] += randint(-1000000000, 1000000000);
		}

		for (int i = 0; i < 3; i++) printf("%d ", a[i]);
		printf("\n");
		for (int i = 0; i < 3; i++) printf("%d ", b[i]);
		printf("\n");
	}
}