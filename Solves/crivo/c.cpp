#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

int pri[N+1];

int isAfraid(int x) {
	
}

int main() {
	ios :: sync_with_stdin(false);
	
	for (int i = 2; i <= N; i++) {
        if (!fat[i]) { // Number is prime
            for (int j = 2*i; j <= N; j += i) {
                fat[j]+= isAfraid(fat[j]);
            }
        }
    }
    
    int n, x;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
    	cin >> x;
    	cout << fat[x] << endl;
	}
    
}
