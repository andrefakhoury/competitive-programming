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
#define MAXN 10000

typedef long long ll;
typedef pair<int, int> pii;

int main () {
	int a, b, c; scanf("%d%d%d", &a, &b, &c);
	int r1 = 2*a + 2*b;
	int r2 = a+b+c;
	int r3 = 2*a + 2*c;
	int r4 = 2*b+2*c;

	printf("%d\n", min(r1, min(r2, min(r3, r4))));
	return 0;
}