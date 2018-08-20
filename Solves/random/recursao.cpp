#include <bits/stdc++.h>
using namespace std;

#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define fastcin ios::sync_with_stdio(0); cin.tie(NULL);
#define PI acos(-1.0)
#define inf 0x3f3f3f3f3f

#define MAXN 100000
#define MAXM 100000

typedef long long ll;
typedef pair<int, int> pii;

int n, x, v[30];

int solve(int at, int somaac) {
	if (at > n) {
		if (!somaac) return 1;
		else return 0;
	}

	return (solve(at+1, somaac-v[at]) + solve(at+1, somaac));
}

int main () {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++) scanf("%d", v+i);
	printf("%d\n", solve(1, x));
	return 0;
}