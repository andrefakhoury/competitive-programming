#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 500005;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

string s, t;

ll valS[MAXN], valT[MAXN];
int ind = 0;

struct HASH{
  size_t operator()(const pair<long long,long long>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
unordered_set<pair<ll, ll>, HASH> freq;
const int MOD[2] = {1000000007, 1000000009};
const int p[2]   = {31, 37};

bool check(long long k) {
	freq.clear();
	pair<long long, long long> cur, hash;

	cur = mp(1, 1), hash = mp(0, 0);
	for (int i = k-1; i >= 0; i--) {
		hash.first = (hash.first + (cur.first * (valS[i]))%MOD[0])%MOD[0];
		if (i > 0) cur.first = (cur.first * p[0])%MOD[0];

		hash.second = (hash.second + (cur.second * (valS[i]))%MOD[1])%MOD[1];
		if (i > 0) cur.second = (cur.second * p[1])%MOD[1];
	}

	freq.insert(hash);
	for (int i = k; i < (int)s.size(); i++) {
		long long last;

		last = ((valS[i-k]) * cur.first)%MOD[0];
		hash.first = (((hash.first - last + MOD[0])%MOD[0])*p[0])%MOD[0];
		hash.first = (hash.first + (valS[i]))%MOD[0];

		last = (((valS[i-k]) * cur.second)%MOD[1] + MOD[1])%MOD[1];
		hash.second = (((hash.second - last + MOD[1])%MOD[1])*p[1])%MOD[1];
		hash.second = (hash.second + (valS[i]))%MOD[1];

		freq.insert(hash);
	}

	cur = mp(1, 1), hash = mp(0, 0);
	for (int i = k-1; i >= 0; i--) {

		hash.first = (hash.first + (cur.first * (valT[i]))%MOD[0])%MOD[0];
		if (i > 0) cur.first = (cur.first * p[0])%MOD[0];

		hash.second = (hash.second + (cur.second * (valT[i]))%MOD[1])%MOD[1];
		if (i > 0) cur.second = (cur.second * p[1])%MOD[1];
	}

	if (freq.find(hash) != freq.end()) {
		ind = 0;
		return true;
	}

	for (int i = k; i < (int)t.size(); i++) {
		long long last;
		
		last = ((valT[i-k]) * cur.first)%MOD[0];
		hash.first = (((hash.first - last + MOD[0])%MOD[0])*p[0])%MOD[0];
		hash.first = (hash.first + (valT[i]))%MOD[0];
		
		last = ((valT[i-k]) * cur.second)%MOD[1];
		hash.second = (((hash.second - last + MOD[1])%MOD[1])*p[1])%MOD[1];
		hash.second = (hash.second + (valT[i]))%MOD[1];

		if (freq.find(hash) != freq.end()) {
			ind = i - k + 1LL;
			return true;
		}
	}

	return false;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> s >> t;

	for (int i = 0; i < (int)s.size(); i++) valS[i] = s[i] - 'a' + 1;
	for (int i = 0; i < (int)t.size(); i++) valT[i] = t[i] - 'a' + 1;

	int lo = 0, hi = t.size(), mi;
	int qtt = 0;

	while (lo <= hi) {
		mi = (lo+hi)/2;
		if (check(mi)) {
			qtt = mi;
			lo = mi + 1LL;
		}

		else hi = mi - 1;
	}

	if (qtt == 0) cout << 0 << endl;
	else {
		string ans;
		for (int i = ind; i < ind + qtt; i++) ans += t[i];
		cout << ans << endl << qtt << endl;
	}

	return 0;
}