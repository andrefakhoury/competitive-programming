#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;

int vec[MAX]; //VETOR PRA FAZER O LIS
int lis(int i, int j) {
	if (vec[i] > v[j]) {
		return max(lis(i+1, j), lis(i+1, i) + 1);
	} else {
		return lis(i+1, j);
	}
}

//com DP
int l[MAX] = {inf}; //Li = menor valor do ultimo elemento da LIS de tamanho i
int vec[MAX];
int lis(int i, int j) {
	l[i] = 
}

int main() {
	
}
