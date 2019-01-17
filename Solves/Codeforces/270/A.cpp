#include <bits/stdc++.h>

#define ll long long

using namespace std;
#define MAXN 10000

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

map<float, int> ang;

int main () {
	int t; scanf("%d", &t);
	float a;
	for (int i = 3; i < 1000; i++) {
		ang[(i-2.0)*180.0/i]++;
	}

	while(t--) {
		scanf("%f", &a);
		if (ang[a]) printf("YES\n");
		else printf("NO\n");
	}
}