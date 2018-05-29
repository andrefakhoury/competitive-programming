#include <bits/stdc++.h>

#define debugg(x) cout << ">>" << (#x) << " :: " << (x) << endl

using namespace std;

int main() {
	int n = 5, max = 11, min = 0, ans=3;
	
	while (ans != 2) {		
		printf("%d\n", n); fflush(stdout);
		scanf("%d", &ans);
		
		if (ans == 1) { //maior
			min = n;
			n += ceil((max-min)/2);
		} else if (ans == 0) { //menor
			max = n;
			n -= floor((max-min)/2);
		}	
	}
	
	return 0;	
}