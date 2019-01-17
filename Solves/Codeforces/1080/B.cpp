#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll PA(int ini, int fin) {
	if (fin < ini) return 0;
	
	int n = 1 + (fin-ini)/2;
	return (ini+fin)*(ll)n/2;
}

int main() {
	int q;
	scanf("%d", &q);
	
	while(q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		
		ll ans = PA(l+l%2, r-r%2);
		ans -= PA(l+(l%2==0), r-(r%2==0));
		
		printf("%lld\n", ans);		
	}
	
	return 0;	
}
