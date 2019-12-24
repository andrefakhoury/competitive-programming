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

inline int get(string s) { 
	cout << s << endl;
	int x; cin >> x;
	if (x == 0) exit(0);

	return x;
}

int main() {
	int x = get("a");
	int n = x+1;

	if (n > 300) get(string(n-1, 'b'));

	string s(n, 'a');
	int d = get(s);

	if (d == n) get(string(n-1, 'b'));
	if (n <= 300 && d == n) get(string(n, 'b'));

	for (int i = 0; i < n; i++) {
		s[i] = 'b';
		int c = get(s);
		if (c < d) d = c;
		else s[i] = 'a';
	}

	assert(0);
}