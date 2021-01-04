#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		if (N == 2010 || N == 2015 || N == 2016 || N == 2017 || N == 2019) printf("HOSTED\n");
		else printf("NOT HOSTED\n");	
	}
	return 0;
}