#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 200010
#define MAXM 100005

//ios::sync_with_stdio(false);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main () {
	vector<ll> val;
	val.pb(1);
	
	ll x; scanf("%lld", &x);
	
	for (ll i = 1, at = 1; at <= x; at+=i, i++) {
		if (at == x) return !printf("1\n");
	} return !printf("0\n");
	
	return 0;
}