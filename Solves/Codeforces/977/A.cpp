#include <bits/stdc++.h>
#define debugg(x) cout << ">>" << (#x) << " :: " << (x) << endl
#define pb push_back

using namespace std;

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < k; i++) {
		if (n%10 != 0) {
			n-=1;
		} else {
			n/=10;
		}
	}
	
	printf("%d\n", n);
	
	
	
	return 0;
}
