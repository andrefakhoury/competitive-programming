#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset((a), (b), sizeof(a))
template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl 
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

	int who = 0; // quem saca
	int pt[2] = {};
	int game[2] = {};

	auto someone = [&](int i) {
		if (pt[i] == 10) return true;
		if (pt[i] >= 5 && (pt[i] - pt[1-i]) >= 2) return true;
		return false;
	};

	auto win = [&]()->int { // atualiza pt, game, retorna se pt[0] > 5 etc
		if (someone(0)) {
			pt[0] = pt[1] = 0;
			return 0;
		}
		if (someone(1)) {
			pt[0] = pt[1] = 0;
			return 1;
		}
		return -1;
	};

	auto print = [&]() {
		if (game[0] == 2) {
			cout << game[0] << " (winner) - " << game[1] << "\n";
		} else if (game[1] == 2) {
			cout << game[0] << " - " << game[1] << " (winner)\n";
		} else {
			cout << game[0] << "(" << pt[0];
			if (who == 0) cout << "*";
			cout << ") - ";

			cout << game[1] << "(" << pt[1];
			if (who == 1) cout << "*";
			cout << ")\n";
		}
	};

	for (int i = 0; i < (int) s.size(); i++) {
		int won = win();
		if (won != -1) {
			game[won]++;
			assert(who == won);
		}

		if (s[i] == 'Q') {
			print();
		} else if (s[i] == 'S') { // ponto de quem sacou
			pt[who]++;
		} else { // ponto de quem recebeu
			who ^= 1;
			pt[who]++;
		}
	}

	return 0;
}