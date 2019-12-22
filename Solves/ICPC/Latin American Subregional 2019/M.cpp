#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

int n, c, t;
vector<int> a;

bool check(long long k) {
	long long cur = 0, qtt = 0;
	for (int i : a) {
		if ((i + t - 1) / t > k) return false;
		if ((cur + i + t - 1) / t <= k) cur += i;
		else {
			cur = i;
			qtt++;
		}
	}
	
	qtt += cur != 0;
	return qtt <= c;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> c >> t;
	a.resize(n);
	for (int& i : a) cin >> i;

	long long lo = 1, hi = 1e14, mi;
	while(lo < hi) {
		mi = (lo + hi) / 2;

		if (check(mi)) hi = mi;
		else lo = mi + 1;
	}

	cout << hi << '\n';

	return 0;
}