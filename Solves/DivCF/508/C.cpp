#include <bits/stdc++.h>
using namespace std;

#define DEBGG(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define fastcin ios::sync_with_stdio(false);
#define SZOF(v) ((int)v.size())
#define xx first
#define yy second

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
#define MAXN 100005

typedef long long ll;
typedef pair<int, int> pii;

int A[MAXN], B[MAXN], n, a, b;
ll sA, sB;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", A+i);
	for (int i = 1; i <= n; i++) scanf("%d", B+i);
	sort(A+1, A+n+1);
	sort(B+1, B+n+1);
	a = b = n;
	while(a && b) {
		if (A[a] > B[b]) sA += A[a--];
		else b--;

		if (!b) {
			a--;
			break;
		}
		if (!a) break;

		if (B[b] > A[a]) sB += B[b--];
		else a--;

		if (!a) {
			b--;
			break;
		}
		if (!b) break;
	}
	while(a > 0) {
		sA += A[a];
		a -= 2;
	}
	while(b > 0) {
		sB += B[b];
		b -= 2;
	}
	return !printf("%lld\n", sA-sB);
}