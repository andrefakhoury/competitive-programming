#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl
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

struct Rect {
	int x, y, z;
	void debug() {
		cerr << "(" << x << ", " << y << ", " << z << ")";
	}
	Rect operator+(Rect p) {
		return {x+p.x, y+p.y, z+p.z};
	}
};

struct Piece {
	Rect ini, dim;
	int type;

	bool colide(Piece const& p) {
		Rect a_min = ini;
		Rect a_max = {this->ini.x + this->dim.x, this->ini.y + this->dim.y, this->ini.z + this->dim.z};
		Rect b_min = p.ini;
		Rect b_max = {p.ini.x + p.dim.x, p.ini.y + p.dim.y, p.ini.z + p.dim.z};

		auto inter = [](int l1, int r1, int l2, int r2)->bool {
			if (l1 > l2) swap(l1, l2), swap(r1, r2);
			// l1 <= l2

			return r1 >= l2;
		};

		bool ret = true;
		ret &= inter(a_min.x, a_max.x, b_min.x, b_max.x);
		ret &= inter(a_min.y, a_max.y, b_min.y, b_max.y);
		ret &= inter(a_min.z, a_max.z, b_min.z, b_max.z);

		return ret;
	}

	void debug() {
		ini.debug(); cerr << " "; (ini+dim).debug();
	}
};

#define y1 asdiuasd
#define x1 asiid3
#define x2 soaid3io
#define y2 kkosajd3uio

int main() {
	int X, Y, Z, q, t; rd(X, Y, Z, q, t);
	vector<Piece> pieces;

	auto count = [&](Piece p)->int {
		int cur = 0;
		for (Piece x : pieces) if (x.colide(p)) cur |= 1 << x.type;
		return __builtin_popcount(cur);
	};

	auto update = [&]()->bool {
		int x, y, z, w, d, h, tp; rd(x, y, z, w, d, h, tp);
		Piece p;
		p.ini = {x, y, z};
		p.dim = {w - 1, d - 1, h - 1};
		p.type = tp;

		if (count(p)) return false;
		pieces.pb(p);
		return true;
	};

	auto query = [&]()->int {
		int x1, y1, x2, y2, z; rd(x1, y1, x2, y2, z);
		Piece p;
		p.ini = {x1, y1, 1};
		p.dim = {x2 - x1, y2 - y1, z - 1};
		return count(p);
	};

	while(q--) {
		int op; rd(op);
		if (op == 1) {
			if (!update()) puts("-1");
		} else {
			printf("%d\n", query());
		}
	}

}