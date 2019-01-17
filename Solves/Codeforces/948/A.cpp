#include <bits/stdc++.h>
using namespace std;

char a[505][505];

int r, c;

bool lobin(int i, int j) {
	if (a[i][j] != "W") return false;

	if (a[i-1][j] == "S") return true;
	if (a[i+1][j] == "S") return true;
	if (a[i][j+1] == "S") return true;
	if (a[i][j-1] == "S") return true;

	return false;
}


int main() {
	scanf("%d%d ", &r, &c);
	for (int i = 1; i <= r; i++)
		scanf("%[^\n\r] ", a[i]+1);

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (a[i][j] == ".") a[i][j] = "D";

	for (int i = 1; i <= r; i++) 
		for (int j = 1; j <= c; j++)
			if (lobin(i, j)) return !printf("No\n");

	printf("Yes\n");
	for (int i = 1; i <= r; i++)
		printf("%s\n", a[i]+1);
}