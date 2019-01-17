#include <bits/stdc++.h>
using namespace std;

#define DEBGG(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define fastcin ios::sync_with_stdio(false);
#define vszz(v) ((int)v.size())
#define xx first
#define yy second

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
#define MAXN 1005

typedef long long ll;
typedef pair<int, int> pii;

int k;
ll n;
ll moveLeft(ll x) {
	x -= k; if (x < 1) x = 1;
	return x;
}
ll moveRight(ll x) {
	x += k; if (x > n) x = n;
	return x;
}

int main () {
	srand(time(NULL));

	ios::sync_with_stdio(false);
	cin >> n >> k;

	ll l = 1, r = n, m, cnt = 4500; cnt/=2;
	string ans;

	while(1) {
		m = (l+r)/2;

		cout << l << " " << m << "\n"; fflush(stdout);
		cin >> ans;
		if (ans == "Bad") return 0;
		if (ans == "Yes") {
			if (l == m) return 0;
			l = moveLeft(l);
			r = moveRight(m);
		} else {
			l = moveLeft(m)+1;
			r = moveRight(r);
		}

		m = (l+r)/2;
		cout << m << " " << r << "\n"; fflush(stdout);
		cin >> ans;
		if (ans == "Bad") return 0;
		if (ans == "Yes") {
			if (m == r) return 0;
			l = moveLeft(m);
			r = moveRight(r);
		} else {
			r = moveRight(m)-1;
			l = moveLeft(l);
		}

		if (r-l <= 50) {
			ll ch = rand()%(r-l+1) + l;
			cout << ch << " " << ch << "\n"; fflush(stdout);
			cin >> ans;
			if (ans == "Bad") return 0;
			if (ans == "Yes") return 0;
			l = moveLeft(l);
			r = moveRight(r);
		}
	}

	return 0;
}