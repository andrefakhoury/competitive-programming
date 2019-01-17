#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> p;

void pre(int at) {
	if (at >= 99) return;

	p.pb(at*10+4);
	p.pb(at*10+7);
	pre(at*10+4); pre(at*10+7);
}

int main() {
	int n; scanf("%d", &n);
	pre(0);

	for (int i = 0; i < (int)p.size(); i++)
		if (n%p[i] == 0) return !printf("YES\n");
	return !printf("NO\n");
}