#include <bits/stdc++.h>

using namespace std;

int solve[101];

int main(int argc, char const *argv[]){
	int n = 100;

	for(int i = 0; i < n; i++){
		solve[i] = 1;
	}

	for(int m = 2; m*m <= n; m++){
		if(solve[m]){
			for(int i = m*m; i < n; i+=m){
					solve[i] = 0;	//não é primo
			}
		}
	}
	
	for(int i = 1; i < n; i++){
		if(solve[i])
			printf("%d ", i);
	}

	return 0;
}