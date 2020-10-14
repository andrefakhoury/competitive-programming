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

#define double long double

const double DINF = 2e10;

struct Line {
	double x;
	int k, b;

	bool operator<(Line const& rhs) const {
		return x < rhs.x;
	}
};

struct Poly {
	ll k, b;
	Poly(ll k, ll b) : k(k), b(b) {}
	Poly operator+(Poly const& rhs) const {
		return Poly(k+rhs.k, b+rhs.b);
	}
	Poly& operator+=(Poly const& rhs) {
		k += rhs.k;
		b += rhs.b;
		return *this;
	}
	Poly& operator-=(Poly const& rhs) {
		k -= rhs.k;
		b -= rhs.b;
		return *this;
	}
	bool operator!=(Poly const& rhs) const {
		return k != rhs.k or b != rhs.b;
	}
};

double get_point(double k, double b) {
	return -b / k;
}

int main() {
	int n; rd(n);

	vector<Line> _ent, _sai;

	vector<double> allx;
	allx.pb(-DINF);
	for (int i = 0; i < n; i++) {
		int k, b; rd(k, b);
		if (k < 0) {
			double p = get_point(k, b);
			_ent.pb({-DINF, k, b});
			_sai.pb({p, k, b});
			allx.pb(p);
		} else if (k == 0) {
			_ent.pb({-DINF, k, b});
		} else {
			double p = get_point(k, b);
			_ent.pb({p, k, b});
			allx.pb(p);
		}
	}

	sort(allx.begin(), allx.end());
	allx.erase(unique(allx.begin(), allx.end()), allx.end());
	auto getx = [&](double x) {
		return lower_bound(allx.begin(), allx.end(), x) - allx.begin();
	};

	int X = allx.size();
	vector<vector<Poly>> ent(X);
	vector<vector<Poly>> sai(X);
	for (Line l : _ent) ent[getx(l.x)].eb(l.k, l.b);
	for (Line l : _sai) sai[getx(l.x)].eb(l.k, l.b);

	int ans = 0;
	Poly cur(0, 0), last(LLONG_MAX, LLONG_MAX);
	for (int x = 0; x < X; x++) {
		for (Poly p : ent[x]) cur += p;
		for (Poly p : sai[x]) cur -= p;
		if (x > 0) ans += cur != last;
		last = cur;
	}

	printf("%d\n", ans);
}