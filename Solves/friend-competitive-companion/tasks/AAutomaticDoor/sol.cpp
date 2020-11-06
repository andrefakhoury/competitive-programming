#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cerr << "[" << #x << "]: " << x << endl
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

int main() {
	__int128 n, m, a, d; rd(n, m, a, d);
	vector<__int128> t(m);
	for (int i = 0; i < m; i++) rd(t[i]);
	t.pb(4e18);

	auto query_func = [&](__int128 x) { return x <= 0 ? 0 : x / a; };
	auto count_func = [&](__int128 left, __int128 right)->__int128 {
		if (left > right) return 0;
		return query_func(right) - query_func(left-1);
	};

	__int128 closed = 0, ans = 0;
	auto count_door = [&](__int128 left, __int128 right)->__int128 { // also update closed
		left = (left + a - 1) / a * a;

		right = min(right, n * a);
		right = right / a * a;
		if (left == 0) left = a;

		if (left > right) return 0;

		__int128 cnt = d / a + 1;
		__int128 N = count_func(left, right);

		__int128 lo = 0, hi = n, mi;
		while(lo < hi) {
			mi = (lo + hi) / 2;
			if (left + mi * a * cnt + d >= right) hi = mi;
			else lo = mi + 1;
		}

		closed = left + hi * a * cnt + d + 1;
		return (N + cnt - 1) / cnt;
	};

	for (int i = 0; i <= m; i++) {
		if (count_func(closed, t[i])) ans += count_door(closed, t[i]);
		if (t[i] < closed) continue;
		closed = t[i] + d + 1;
		ans++;
	}

	ans--;
	string answer;
	while(ans) answer.pb(ans % 10 + '0'), ans /= 10;
	reverse(answer.begin(), answer.end());
	printf("%s\n", answer.c_str());
}
