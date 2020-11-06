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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s; cin >> s;

	if (s.size() <= 3) {
		sort(s.begin(), s.end());
		do {
			if (s[0] == '0') continue;
			if (stoi(s) % 8 == 0) {
				puts("Yes");
				return 0;
			}

		} while(next_permutation(s.begin(), s.end()));

		puts("No");
		return 0;
	}

	int f[10] = {};
	for (char c : s) f[c-'0']++;

	auto go = [&](int n) {
		string t = to_string(n);
		if (t.size() < 3u) return false;
		bool ok = true;
		for (int i = 0; i < 3; i++) {
			ok &= f[t[i]-'0'] >= 1;
			f[t[i]-'0']--;
		}
		for (int i = 0; i < 3; i++) {
			f[t[i]-'0']++;
		}
		return ok;
	};

	bool ans = false;
	for (int i = 0; i < 1000; i++) if (i % 8 == 0) {
		ans |= go(i);
	}
	puts(ans ? "Yes" : "No");
}
