#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) print(__VA_ARGS__), print('\n')

const int MAXN = 1e6 + 10;

ll pot[13];
vector<int> fac[MAXN];
bool isComp[MAXN];

inline void run_test() {
	ll A, B; rd(A, B);
	string s = to_string(B);
	ll ans = -1;

	auto split = [](string const& s, ll& d1, ll& d2) {
		string s1 = s.substr(0, s.size()/2);
		string s2 = s.substr(s.size()/2);
		if (s1.empty()) d1 = 0;
		else d1 = stoll(s1);
		d2 = stoll(s2);
	};

	ll d1, d2;
	split(s, d1, d2);
	if (d1 && d2 && gcd(d1, d2) > 1) {
		print(B);
		return;
	}

	auto get_len = [](ll n) {
		int nn = 0;
		while(n) nn++, n /= 10;
		return nn;
	};

	auto test = [&ans, &get_len, A, B](ll d1, ll d2, ll k, int n1, int n2) {
		ll dn = d2 / k * k;
		ll cur = d1 * pot[n2] + dn;
		if (n2 >= n1 && dn > 0 && cur >= A && cur <= B) ans = max(ans, cur);
	};

	auto go = [&test, &get_len, &split, &s](ll d1, ll d2) {
		int n2 = (s.size() + 1) / 2;
		string cur_s2 = to_string(d2);
		if ((int) cur_s2.size() != n2) cur_s2 = string(n2 - (int) cur_s2.size(), '0') + cur_s2;
		string cur_s = (d1 ? to_string(d1) : "") + cur_s2;
		split(cur_s, d1, d2);
		int n1 = get_len(d1);
		for (int k : fac[d1]) test(d1, d2, k, n1, (cur_s.size() + 1) / 2);
	};

	go(d1, d2);
	for (int i = 1; i <= 50; i++) if (d1 - i >= 0) {
		go(d1 - i, pot[(s.size() + 1) / 2] - 1);
	}


	if (ans == -1) print("impossible");
	else print(ans);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	pot[0] = 1;
	for (int i = 1; i < 13; i++) pot[i] = pot[i-1] * 10;
	for (int i = 2; i < MAXN; i++) if (!isComp[i]) {
		for (int j = i; j < MAXN; j += i) {
			fac[j].pb(i);
			isComp[j] = true;
		}
	}

#ifndef LOCAL_PC
	freopen("halfnice.in", "r", stdin);
#endif

	int T; rd(T);
	for (int cs = 1; cs <= T; cs++) {
		cout << "Case " << cs << ": ";
		run_test();
	}
}