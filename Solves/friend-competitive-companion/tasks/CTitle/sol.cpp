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

void imp() {
	cout << "IMPOSSIBLE\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int k; cin >> k;
	string s; cin >> s;
	int n = s.size();

	set<char> left;
	for (int i = 0; i < k; i++) left.insert(i + 'a');

	// palindrome
	for (int i = 0, j = n - 1; i < j; i++, j--) {
		bool bi = s[i] != '?';
		bool bj = s[j] != '?';
		if (bi && bj && s[i] != s[j]) imp();
		else if (bi && !bj) s[j] = s[i];
		else if (!bi && bj) s[i] = s[j];
	}

	for (char c : s) left.erase(c);

	// comeca do meio indo pro comeco, usando o maior cara ate o menor
	for (int i = (n - 1) / 2; i >= 0; i--) if (s[i] == '?') {
		int j = n - i - 1;
		char c = left.size() ? *left.rbegin() : 'a';
		left.erase(c);
		s[i] = s[j] = c;
	}

	if (left.size()) imp();
	cout << s << "\n";
}