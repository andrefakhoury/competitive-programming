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
};

struct Piece {
	Rect ini, dim;
	int type;

	/**
	 * Function func_Intersect(ByVal cuboid1_MinX As Double, ByVal cuboid1_MaxX As Double, ByVal cuboid1_MinY As Double, ByVal cuboid1_MaxY As Double, ByVal cuboid1_MinZ As Double, ByVal cuboid1_MaxZ As Double, ByVal cuboid2_MinX As Double, ByVal cuboid2_MaxX As Double, ByVal cuboid2_MinY As Double, ByVal cuboid2_MaxY As Double, ByVal cuboid2_MinZ As Double, ByVal cuboid2_MaxZ As Double) As Boolean
    func_Intersect = True

End Function

	 * @param p
	 * @return
	 */
	bool colide(Piece const& p) {
		Rect a_min = ini;
		Rect a_max = {this->ini.x + this->dim.x - 1, this->ini.y + this->dim.y - 1, this->ini.z + this->dim.z - 1};
		Rect b_min = p.ini;
		Rect b_max = {p.ini.x + p.dim.x - 1, p.ini.y + p.dim.y - 1, p.ini.z + p.dim.z - 1};

		bool ret = true;
		if (a_max.x < b_min.x) ret = false;
		else if (b_max.x < a_min.x) ret = false;
		else if (a_max.y < b_min.y) ret = false;
		else if (b_max.y < a_min.y) ret = false;
		else if (a_max.z < b_min.z) ret = false;
		else if (b_max.z < a_min.z) ret = false;

		return ret;
	}
};

int main() {
	int X, Y, Z, q, t; rd(X, Y, Z, q, t);
	vector<Piece> pieces;

	auto count = [&](Piece p)->int {
		int cur = 0;
		for (Piece x : pieces) if (p.colide(x)) cur |= 1 << x.type;
		return __builtin_popcount(cur);
	};

	auto has = [&](Piece p)->bool {
		for (Piece x : pieces) if (p.colide(x)) return true;
		return false;
	};

	auto update = [&](auto&& update)->bool {
		int x, y, z, w, d, h, t; rd(x, y, z, w, d, h, t);
		Piece p;
		p.ini = {x, y, z};
		p.dim = {w, d, h};
		p.type = t;

		int lox = 0, hix = w;
		while(lox < hix) {
			int mix = (lox + hix + 1) / 2;
			Piece px = p; px.dim = {mix, 1, 1};
			if (!has(px)) lox = mix;
			else hix = mix - 1;
		}
		if (lox == 0) return false;

		if (count(p)) return false;
		pieces.pb(p);
		return true;
	};

	auto query = [&]()->int {
		int x1, y1, x2, y2, z; rd(x1, y1, x2, y2, z);
		Piece p;
		p.ini = {x1, y1, z};
		p.dim = {x2 - x1 + 1, y2 - y1 + 1, 1};
		return count(p);
	};

	while(q--) {
		int op; rd(op);
		if (op == 1) {
			if (!update(update)) puts("-1");
		} else {
			printf("%d\n", query());
		}
	}

}
