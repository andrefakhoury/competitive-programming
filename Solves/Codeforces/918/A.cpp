#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll f[1005];
set<ll> fib;
int n;

int main(void){
	scanf("%d", &n);
	
	f[1] = f[2] = 1;
	fib.insert(1);
	for(int i = 3; i < 1002; i++){
		f[i] = f[i-1] + f[i-2];
		fib.insert(f[i]);
	}

	for(int i = 1; i <= n; i++){
		if(fib.count(i)){
			printf("O");
		}
		else{
			printf("o");
		}
	}
	printf("\n");

	return 0;
}