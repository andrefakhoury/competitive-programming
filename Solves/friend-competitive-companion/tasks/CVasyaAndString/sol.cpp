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
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	string s; cin >> s;

	auto check = [&](int len, char c)->bool {
		int freq[2] = {};
		for (int i = 0; i < len; i++) freq[s[i]-'a']++;
		if (freq[1-c+'a'] <= k) return true;
		for (int i = len; i < n; i++) {
			freq[s[i-len]-'a']--;
			freq[s[i]-'a']++;
			if (freq[1-c+'a'] <= k) return true;
		}
		return false;
	};

	int lo = 1, hi = n, mi;
	while(lo < hi) {
		mi = (lo + hi + 1) / 2;
		if (check(mi, 'a') or check(mi, 'b')) lo = mi;
		else hi = mi - 1;
	}

	cout << lo << "\n";
}