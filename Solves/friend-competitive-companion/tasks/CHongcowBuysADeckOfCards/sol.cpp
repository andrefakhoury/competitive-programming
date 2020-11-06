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
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

struct Card {
	char c;
	int r, b;

	inline void read() {
		scanf(" %c%d%d", &c, &r, &b);
	}
} d[16];

//pii memo[1 << 16];

struct State {
	int rounds, RED, BLUE;
} memo[1 << 16];

State solve(int mask, int A, int B, int n) {
	if (__builtin_popcount(mask) == n) return {0, 0, 0};

	State& ret = memo[mask];
	if (ret.rounds != -1) return ret;

	auto best = [](State& a, State b) {
		if (b.rounds < a.rounds) a = b;
	};

	ret = {INF, 0, 0};
	for (int i = 0; i < n; i++) if (((mask>>i)&1) == 0) {
		int pa = max(0, d[i].r - A);
		int pb = max(0, d[i].b - B);
		State cur = solve(mask | (1 << i), A + (d[i].c == 'R'), B + (d[i].c == 'B'), n);

		int qtA = min(cur.rounds - cur.RED, pa);
		int qtB = min(cur.rounds - cur.BLUE, pb);

		pa -= qtA;
		pb -= qtB;
		cur.RED += pa;
		cur.BLUE += pb;
		cur.rounds += max(pa, pb);
		best(ret, cur);
	}

	return ret;
}

int main() {
	int n; rd(n);
	for (int i = 0; i < n; i++) d[i].read();
	mset(memo, -1);
	int ans = solve(0, 0, 0, n).rounds + n;
	printf("%d\n", ans);
}
