#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int N, K;
	long double fat = 0;
	long double fatN = 1;
	long double fatK = 1;
	long double fatNK = 1;
	
	cin >> N >> K;
	
	if (N == K) {
		cout << 1 << endl;
	} else if (N < K) {
		cout << 0 << endl;
	} else {
		for (int i = K+1; i <= N; i++) {
			fatN *= i;
		}
		for (int i = 1; i <= N-K; i++) {
			fatNK *= i;
		}
		
		fat = (fatN)/(fatNK);
		cout << fixed << setprecision(0) << fat << endl;
	}	
	
	return 0;
	
}