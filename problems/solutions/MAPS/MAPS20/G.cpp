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

stack<ll> st;

inline void st_push() {
	string x;
	for (char c; cin >> c, c != 'N'; )
		x += c;

	ll num = 0, xx = 1;
	for (int i = x.size()-1; i > 0; i--) {
		if (x[i] == 'T') num += xx;
		xx *= 2;
	}

	if (x[0] == 'T') num = -num;
	st.emplace(num);
}

inline void st_copy() {
	if (st.empty()) {
		cout << "Invalid copy operation\n";
	} else {
		ll n1 = st.top();
		st.emplace(n1);
	}
}

inline void st_swap() {
	if (st.size() < 2) {
		cout << "Invalid swap operation\n";
	} else {
		ll n1 = st.top();
		st.pop();
		ll n2 = st.top();
		st.pop();

		st.emplace(n1);
		st.emplace(n2);
	}
}

inline void st_remove() {
	if (st.empty()) {
		cout << "Invalid remove operation\n";
	} else st.pop();
}

inline void st_add() {
	if (st.size() < 2) {
		cout << "Invalid addition operation\n";
	} else {
		ll n1 = st.top();
		st.pop();
		ll n2 = st.top();
		st.pop();
		st.emplace(n1+n2);
	}
}

inline void st_sub() {
	if (st.size() < 2) {
		cout << "Invalid subtraction operation\n";
	} else {
		ll n1 = st.top();
		st.pop();
		ll n2 = st.top();
		st.pop();
		st.emplace(n2-n1);
	}
}

inline void st_mul() {
	if (st.size() < 2) {
		cout << "Invalid multiplication operation\n";
	} else {
		ll n1 = st.top();
		st.pop();
		ll n2 = st.top();
		st.pop();
		st.emplace(n1*n2);
	}
}

inline void st_div() {
	if (st.size() < 2) {
		cout << "Invalid division operation\n";
	} else if (st.top() == 0) {
		cout << "Division by zero\n";
	} else {
		ll n1 = st.top();
		st.pop();
		ll n2 = st.top();
		st.pop();
		st.emplace(n2/n1);
	}
}

inline void st_print() {
	if (st.empty()) {
		cout << "Invalid print operation\n";
	} else {
		ll n1 = st.top();
		st.pop();
		cout << n1 << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	map<string, function<void()>> mp;
	mp["SS"] = st_push;
	mp["SNS"] = st_copy;
	mp["SNT"] = st_swap;
	mp["SNN"] = st_remove;
	mp["TSSS"] = st_add;
	mp["TSST"] = st_sub;
	mp["TSSN"] = st_mul;
	mp["TSTS"] = st_div;
	mp["TNST"] = st_print;

	string t;
	for (char c; cin >> c;) {
		t += c;
		if (mp.count(t)) {
			mp[t]();
			t.clear();
		}
	}

	assert(t.empty());
}