#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int N = 2007, inf = 0x3f3f3f3f;

string s; 
ll k;

int F[N][N];
ll G[N][N];

int f(int i, int j) {
	if(j == i) return 0;
	if(j < i) return 0;

	int & st = F[i][j];

	if(st == -1) {
		if(s[i] == s[j]) {
			st = f(i + 1, j - 1);
		} else {
			st = 1 + min(f(i + 1, j), f(i, j - 1));
		}
	}
	return st;
}

const ll MAX = 2e18;

ll g(int i, int j) {
	if(j == i) return 1;
	if(j < i) return 1;

	ll & st = G[i][j];

	if(st == -1) {
		st = 0;

		if(s[i] == s[j]) {
			st = g(i + 1, j - 1);
		} else {
			if(1 + f(i + 1, j) == f(i, j)) st += g(i + 1, j);
			if(1 + f(i, j - 1) == f(i, j)) st += g(i, j - 1);
			if(st > MAX) st = MAX;
		}
	}
	return st;
}

string pre, suf;

void find(int i, int j, ll cur = 0) {
	if(j < i) return;
	if(i == j) {
		pre += s[i];
		return;
	}

	if(s[i] == s[j]) {
		pre += s[i];
		suf += s[j];
		find(i+1, j-1, cur);
		return;
	}

	if(f(i+1, j) != f(i, j-1)) {
		if(f(i+1, j) < f(i, j-1)) {
			suf += s[i];
			pre += s[i];
			find(i + 1, j, cur);
		} else {
			suf += s[j];
			pre += s[j];
			find(i, j-1, cur);
		}
		return;
	}

	ii a = ii(1, 0);
	ii b = ii(0, -1);


	if(s[j] < s[i]) { // o menor vai ser o segundo
		swap(a, b);
	}

	if(cur + g(i + a.fi, j + a.se) >= k) {
		suf += s[a.fi? i : j];
		pre += s[a.fi? i : j];
		find(i + a.fi, j + a.se, cur);
	} else {
		suf += s[b.fi? i : j];
		pre += s[b.fi? i : j];

		cur += g(i + a.fi, j + a.se);

		find(i + b.fi, j + b.se, cur);		
	}
}

int main() {
	memset(F, -1, sizeof F);
	memset(G, -1, sizeof G);
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> s;
	cin >> k;

	ll tot = g(0, s.size()-1);
	if(tot < k) {
		cout << "NONE\n";
		return 0;
	}

	find(0, s.size()-1);
	reverse(suf.begin(), suf.end());
	cout << pre + suf << endl;
}