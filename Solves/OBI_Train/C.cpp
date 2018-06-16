#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 100000
#define MAXM 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main () {
	int t, d, x; scanf("%d", &t);
	ll n;
	while(t--) {
		scanf("%d", &d);
		vector<int> v;
		for(int i = 0; i < d; i++)
			scanf("%d", &x); v.pb(x);
		scanf("%lld", &n);
		sort(v.begin(), v.end());
		
		
	}

	return 0;
}