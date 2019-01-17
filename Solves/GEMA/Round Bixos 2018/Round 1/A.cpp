#include <bits/stdc++.h>

using namespace std;

char megas[7][11];

int main(void) {	
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> megas[i][j];
		}
	}
	
	int num[6];
	int linha, coluna;
	int jj;
	
	bool ganhou = true;
	for (int i = 0; i < 6; i++) {
		cin >> num[i];
		jj = num[i];
		
		linha = jj/10;
		if (jj%10 != 0) linha++;
		coluna = jj - (10*(linha-1));
			
		if (megas[linha][coluna] != 'x') {
			ganhou = false;
		}
	}
	
	if (ganhou) {
		cout << "S" << endl;
	} else {
		cout << "N" << endl;
	}
	
	return 0;
	
}