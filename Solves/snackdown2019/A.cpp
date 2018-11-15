#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

const int MAXN = 100005;
typedef long long ll;

char a[MAXN];
int n;

int main() {
	ios::sync_with_stdio(false);

	int t; scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		scanf("%s", a+1);

		printf("%d\n", solve(1));
	}
	
	return 0;
}