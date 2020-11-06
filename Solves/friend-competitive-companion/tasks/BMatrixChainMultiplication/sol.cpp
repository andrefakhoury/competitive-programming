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
const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

bool error;

struct Matrix {
	int n, m;
	ll cur;
	Matrix() : n(), m(), cur() {}
	Matrix& operator*=(Matrix const& rhs) {
		if (n == 0 && m == 0) {
			n = rhs.n;
			m = rhs.m;
			cur = rhs.cur;
			return *this;
		}

		if (m != rhs.n) error = true;
		else {
			cur += 1ll * n * m * rhs.m;
			cur += rhs.cur;
			m = rhs.m;
		}
		return *this;
	}
} mat[26];

Matrix solve(int& i, string const& s) {
	int n = s.size();

	Matrix ans;
	for (; i < n; i++) {
		Matrix toMul;
		if (s[i] == '(') toMul = solve(++i, s);
		else if (s[i] == ')') break;
		else toMul = mat[s[i]-'A'];
		ans *= toMul;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		cin >> mat[c-'A'].n >> mat[c-'A'].m;
	}

	string s;
	while(cin >> s) {
		error = false;
		int i = 0;
		Matrix ans = solve(i, s);
		if (error) cout << "error\n";
		else cout << ans.cur << "\n";
	}





}