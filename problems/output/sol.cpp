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
#define print(...) { print(__VA_ARGS__); print('\n'); }

struct Solver {
	const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

	inline void run_test(int test_case) {
		string s; rd(s);

		string t;
		int n = s.size();
		for (int i = 0; i < n; i++) {
			if (s[i] == '/' && i+1 < n && s[i+1] == '/') continue;
			t += s[i];
		}
		while(t.size() && t.back() == '/') t.pop_back();
		if (t.empty()) t = "/";
		print(t);
	}

	inline void prepare() { // first thing to run
		ios::sync_with_stdio(false); cin.tie(nullptr);
	}
};

/* **************************************************** */

// CHANGE HERE if there are multiple test cases
const enum TEST_TYPE { SINGLE, MULTIPLE, MULTIPLE_EOF } test_type = SINGLE;

inline void go_for_it() {
	if (test_type == SINGLE) {
		Solver solver;
		solver.prepare();
		solver.run_test(1);
	} else if (test_type == MULTIPLE) {
		Solver solver;
		solver.prepare();
		int test_count; rd(test_count);
		for (int test_number = 1; test_number <= test_count; test_number++)
			solver.run_test(test_number);
	} else {
		Solver solver;
		solver.prepare();
		for (int test_number = 1;; test_number++)
			solver.run_test(test_number);
	}
}

int main() {
    go_for_it();
}
