#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

long long converte(char a[20], bool z) {
	int len = strlen(a), ret = 0;
	long long p = 1;
	for (int i = len-1; i >= 0; i--) {
		ret += (a[i]-"0")*p;
		if (a[i] != "0" || !z) p *= 10;
	}
	return ret;
}

int main() {
	char a[20], b[20], sum[20];
	long long ori, noz;

	scanf("%s %s", a, b);

	ori = converte(a, false) + converte(b, false);
	sprintf(sum, "%lld", ori);
	ori = converte(sum, true);
	noz = converte(a, true)  + converte(b, true);

	return !printf(ori == noz ? "YES\n" : "NO\n");
}