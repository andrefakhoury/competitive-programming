#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
#define MAXN 100005

char c[MAXN];

int main() {
	int n, p; scanf("%d%d", &n, &p);
	ll ans = 0;
	
	int tam = 1, pot = 10;
	ll a = 0, b;
	for (int i = 0; i < n; i++) {
		a++; if (!(a%pot)) { tam++; pot*=10; }
		sprintf(c, "%lld", a);
		
		for (int k = tam-1, j = tam; j < 2*tam; j++, k--) c[j] = c[k];
		c[2*tam] = "\0";
		sscanf(c, "%lld", &b);
		ans = (ans+(b%p))%p;
	}
	
	cout << (ans%p) << endl;
	return 0;
}
