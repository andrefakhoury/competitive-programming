#include <bits/stdc++.h>

using namespace std;
int main(){
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	int l1, r1, l2, r2;
	cin >> N;
	for(int i=0; i < N; i++){
		cin >> l1 >> r1 >> l2 >> r2;
		if(r2 == r1 and l2 == r1)r1--;
		else if(r2 == r1) r2--;
		cout << r1 << ' ' << r2 << endl;  
	}
	
	return 0;
}