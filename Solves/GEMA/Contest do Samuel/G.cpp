#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int p[2]   = {31, 37};
const int MOD[2] = {1000000007, 1000000009};
const ll INV[2] = {129032259, 297297300};

bool isSubstring(string& s, string& t) {
	if (t.size() > s.size()) return false;
	if (t.size() == s.size()) return s == t;

	pair<ll, ll> hashT = {0LL, 0LL};
	pair<ll, ll> hashS = {0LL, 0LL};
	pair<ll, ll> pot = {1LL, 1LL};

	for (char c : t) {
		int id = c - 'a' + 1;

		hashT.first = (hashT.first + id * pot.first) % MOD[0];
		hashT.second = (hashT.second + id * pot.second) % MOD[1];

		pot.first = (pot.first * p[0]) % MOD[0];
		pot.second = (pot.second * p[1]) % MOD[1];
	}

	pot = {1LL, 1LL};
	for (int i = s.size() - t.size(); i < s.size(); i++) {
		int id = s[i] - 'a' + 1;

		hashS.first = (hashS.first + id * pot.first) % MOD[0];
		hashS.second = (hashS.second + id * pot.second) % MOD[1];

		if (i != s.size() - 1) {
			pot.first = (pot.first * p[0]) % MOD[0];
			pot.second = (pot.second * p[1]) % MOD[1];
		}
	}

	if (hashS == hashT) return true;

	pair<ll, ll> last;
	for (int i = s.size() - t.size() - 1; i >= 0; i--) {
		last.first =  ((s[i + t.size()] - 'a' + 1) * pot.first)  % MOD[0];
		last.second = ((s[i + t.size()] - 'a' + 1) * pot.second) % MOD[1];

		int id = s[i] - 'a' + 1;

		hashS.first =  ((((hashS.first  - last.first  + MOD[0])%MOD[0]) * p[0])%MOD[0] + id)%MOD[0];
		hashS.second = ((((hashS.second - last.second + MOD[1])%MOD[1]) * p[1])%MOD[1] + id)%MOD[1];

		if (hashS == hashT) return true;
	}

	return false;
}

int qttRight(string& s, string& t) {
	int k = min(s.size(), t.size());
}

int abc() {
	

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string a, b, c;

	while (cin >> a >> b >> c) {
		isSubstring(a, b);
	}
}