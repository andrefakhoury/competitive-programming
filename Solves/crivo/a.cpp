#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

int fat[N+1];

int main() {
	
	for (int i = 2; i <= N; i++) {
        if (!fat[i]) { // Number is prime
            for (int j = 2*i; j <= N; j += i) {
                fat[j]++;
            }
        }
    }
    
    int d;
    scanf("%d", &d);
    
    while(d != 0) {
    	printf("%d : %d\n", d, fat[d]);
    	scanf("%d", &d);
	}
    
}
