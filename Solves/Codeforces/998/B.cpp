#include <bits/stdc++.h>

using namespace std;

#define MAXN 105
#define MAXB 105

int N, B, v[MAXN];

int main() {
	vector<int> custos;
	scanf("%d %d", &N, &B);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	int qt = 1, flag = 0; //0 par 1 impar

	int qtPar = 0, qtImpar = 0;

	if (v[0]%2) { flag = 1; qtImpar++; }
	else  { flag = 0; qtPar++; }

	for (int i = 1; i < N; i++) {
		if (v[i]%2) {
			qtImpar++;
		} else {
			qtPar++;
		}
		if (qtImpar == qtPar) {
			qtImpar = qtPar = 0;
			if (i < N-1) custos.push_back(abs(v[i]-v[i+1]));
		}
	}
    
    sort(custos.begin(), custos.end());
    long long soma = 0;
    int i = 0, qtD = 0;
    while(i < custos.size()) {
        if (soma + custos[i] <= B) {
            soma += custos[i]; qtD++;
        } else {
            break;
        }
        
        i++;
    }
    printf("%d\n", qtD);
}