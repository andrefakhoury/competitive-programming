#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;
typedef long long ll;
typedef map<int, int>::iterator ite;

int solve(ite i, ite e) {
	if (i == e) return 0;

	

	return 
}

int main() {
	int t; scanf("%d", &t);

	while (t--) {
		map<int, int, greater<int> > f;
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", a+i);
			f[a[i]]++;
		}
		printf("%d\n", solve(f.begin(), f.end()));		
	}
	
	return 0;
}
