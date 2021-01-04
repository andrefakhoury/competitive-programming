#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

int main() {
	int n; scanf("%d", &n);

	int ans = 0;
	map<int, int> freq;
	while(n--) {
		int x; scanf("%d", &x);
		freq[x]++;
		if (freq[x] == 1) ans++;
	}

	printf("%d\n", ans);

	return 0;
}
