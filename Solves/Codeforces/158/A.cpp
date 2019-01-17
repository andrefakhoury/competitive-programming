#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, k, x = 0, nota;
	int a1, y;
	vector<int> parts;
	
	scanf("%d %d", &n, &k);
	for (a1 = 0; a1 < n; a1++) {
		scanf("%d", &y);
		parts.push_back(y);
		if (a1+1 == k) nota = y;
	}
	
	for (a1 = 0; a1 < n; a1++) {
		if (parts[a1] >= nota && parts[a1] != 0) x++;
		else break;
	}
	
	printf("%d\n",x);
	return 0;
	
}
