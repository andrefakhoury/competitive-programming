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

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; rd(n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) rd(a[i]);

	vector<char> v(n);
	v[0] = '=';

	bool ans = false;

	for (int i = 0; i < n; i++) {
		if (a[i] == -1) a[i] = 0;
		else break;
	}

	
	int last = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] == -1) v[i] = 'X';
		else {
			if (a[i] == last) v[i] = '=';
			else if (a[i] < last) v[i] = '-';
			else v[i] = '+';
			last = a[i];
		}
	}

	vector<int> neg = {-1}, pos = {-2}, notm1 = {-1};
	for (int i = 0; i < n; i++) {
		if (v[i] == '-') neg.pb(i);
		else if (v[i] == '+') pos.pb(i);
		if (v[i] != 'X') notm1.pb(i);
	}
	neg.pb(n);
	pos.pb(n+1);
	notm1.pb(n+2);

	auto check = [&](int l, int r) {
		// primeiro cara entre [l, r]

		int prim_neg = lower_bound(neg.begin(), neg.end(), l + 1) - neg.begin();
		int last_pos = int(lower_bound(pos.begin(), pos.end(), r + 1) - pos.begin()) - 1;

		if (a[l] == -1) {
			// primeiro cara nao -1 (-, +, =) vira =
			auto pnm1 = upper_bound(notm1.begin(), notm1.end(), l);
			if (*pnm1 >= r) return true;
			if (prim_neg >= 0 && prim_neg < (int) neg.size() && *pnm1 == neg[prim_neg]) prim_neg++;
			if (last_pos >= 0 && last_pos < (int) pos.size() && *pnm1 == pos[last_pos]) last_pos++;
		}

		int pneg = neg[prim_neg];
		int lpos = pos[last_pos];


		if (pneg >= l && pneg <= r && lpos >= l && lpos <= r && pneg < lpos) return false;

		// se nao se intersecta, so precisa que
		if (a[l] != -1 && v[l+1] == '-') return false;
		if (a[r-1] != -1 && v[r] == '+') return false;

		return true;
	};

	for (int sz = 3; !ans && sz <= n; sz++) {
		bool ok = true;
		if (n % sz) ok &= (n % sz >= 3) && check(n - (n % sz), n - 1);

		for (int i = 0; i + sz - 1 < n && ok; i += sz) {
			ok &= check(i, i + sz - 1);
		}

		ans |= ok;
	}
	print(ans ? "Y" : "N");	
}
