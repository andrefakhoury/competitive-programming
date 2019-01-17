#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	int n; scanf("%d", &n);

	set<ll> ans;
	ans.insert(1);
	ans.insert((ll)n*(n+1)/2);

	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			ans.insert((ll)(1+(n-i+1))*(n/i)/2);
			ans.insert((ll)(1+(n-(n/i)+1))*(i)/2);
		}
	}
	
	// sort(ans.begin(), ans.end());
	// ans.erase( unique( ans.begin(), ans.end() ), ans.end() );

	for (auto it : ans) printf("%lld ", it);
	printf("\n");
	
	return 0;
}