#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 100005
#define MAXM 100000

//ios::sync_with_stdio(false);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

map<ll, int> num;

int main () {
	int n; scanf("%d", &n);
	ll x;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		num[x]++;
	}
	
	ll best = -1, ind = -1;
	
	
	for (map<ll,int>::iterator it=num.begin(); it!=num.end(); ++it)
		if (it->second > best) {
			best = it->second;
			ind = it->first;
		}
	
	printf("%lld %lld\n", ind, best);
	return 0;
}