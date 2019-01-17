#include <bits/stdc++.h>
#define debugg(x) cout << ">>" << (#x) << " :: " << (x) << endl

using namespace std;

typedef pair<int, int> ii;

int main(void) {
	ii pos = {1, 1};
	
	int n, m, nX = n;
	long long int k;
	
	scanf("%d %d %lld", &n, &m, &k);
	
	long long int mov = 0;
	long long int bkp = 0;
	
	char com = "D";
	int cont = 0;
	
	while (mov < k) {		
		if (com == "D") {
			mov += n-1;
			pos.first = n;
			if (mov >= k) {
				printf("%d 1\n", k+1, pos.second);
				return 0;
			}
			com = "R";
		} else if (com == "R") {
			mov += m-pos.second;
			pos.second += m-pos.second;
			if (mov >= k) {
				printf("%d %d\n", pos.first, pos.second - (mov-k));
				return 0;
			} else {
				com = "U";
				cont = 0;
			}
		} else if (com == "U") {
			pos.first--;
			if (cont == 0) com = "L";
			else com = "R";
			mov++;
		} else if (com == "L") {
			pos.second = 2;
			mov += m-pos.second;
			if (mov >= k) {
				printf("%d %d\n", pos.first, 2+mov-k);
				return 0;
			} else {
				com = "U";
				cont = 1;
			}
		}
		bkp = mov;
	}
	
	printf("%d %d\n", pos.first, pos.second);
	return 0;
	
	
	return 0;
}
