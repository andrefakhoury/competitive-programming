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
	int n; scanf("%d", &n);
	
	int ans = 0;
	for (int i = 1; i*6 <= n; i++) {
		if (n%(6*i)==0) ans++;
	}
	printf("%d\n", ans);
	
	
	
	return 0;
}