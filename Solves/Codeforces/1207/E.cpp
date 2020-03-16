#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int ask(vector<int>& a) {
	cout << "? ";
	for (int i = 0; i < 100; i++) cout << a[i] << " \n"[i == 99];
	cout.flush();
	
	int x; cin >> x;
	if (x == -1) assert(0);
	return x;
}

inline void guess(int x) {
	cout << "! " << x << endl;
	cout.flush();
	exit(0);
}

int main() {
	vector<int> a1, a2;
	for (int i = 1; i <= 100; i++) {
		a1.eb(i);
		a2.eb(i << 7);
	}

	int a = ask(a1);
	int b = ask(a2);
	int res = 0;

	for (int i = 7; i < 14; i++) if (a & (1 << i)) res |= 1 << i;
	for (int i = 0; i <  7; i++) if (b & (1 << i)) res |= 1 << i;
	guess(res);
}