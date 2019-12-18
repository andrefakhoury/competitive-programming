#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void _solve() {
	string s; cin >> s;
	map<char, int> freq;
	for (char c : s) freq[c]++;

	int U = freq['U'];
	int D = freq['D'];
	int L = freq['L'];
	int R = freq['R'];

	int v = min(U, D);
	int h = min(L, R);

	if (!h && !v) {
		cout << 0 << "\n\n";
	} else if (!h) {
		if (v >= 1) {
			cout << "2\nUD\n";
		} else {
			cout << 0 << "\n\n";
		}
	} else if (!v) {
		if (h >= 1) {
			cout << "2\nLR\n";
		} else {
			cout << 0 << "\n\n";
		}
	} else {
		cout << (v+h)*2 << "\n";
		for (int i = 0; i < v; i++) cout << "U";
		for (int i = 0; i < h; i++) cout << "R";
		for (int i = 0; i < v; i++) cout << "D";
		for (int i = 0; i < h; i++) cout << "L";
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) _solve();

	return 0;
}