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
	int n; cin >> n;
	vector<string> a(n);
	for (auto& s : a) cin >> s;

	string ini, mid, fim;

	bool ok = true;
	for (string& s : a) if (ok) {
		s += '*';
		vector<string> cur;
		string t;
		for (char c : s) {
			if (c == '*') {
				cur.eb(t);
				t.clear();
			} else t += c;
		}

		string& ac_ini = cur.front();
		if (ac_ini.size()) {
			for (int i = 0; i < (int) min(ac_ini.size(), ini.size()); i++) {
				if (ac_ini[i] != ini[i]) {
					ok = false;
					break;
				}
			}
			
			ini = max(ini, ac_ini);
		}
		
		string& ac_fim = cur.back();
		if (ac_fim.size()) {
			reverse(ac_fim.begin(), ac_fim.end());
			for (int i = 0; i < (int) min(ac_fim.size(), fim.size()); i++) {
				if (ac_fim[i] != fim[i]) {
					ok = false;
					break;
				}
			}

			fim = max(fim, ac_fim);
		}

		for (int i = 1; i + 1 < (int) cur.size(); i++) if (cur[i].size())
			mid += cur[i];
	}

	reverse(fim.begin(), fim.end());
	string ans = ini + mid + fim;
	if (!ok) ans = "*";

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int __T__; cin >> __T__;
	for (int xx = 1; xx <= __T__; xx++) {
		cout << "Case #" << xx << ": ";
		_solve_();
	}
	return 0;
}