#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector<long long int> soma;

int main() {
	int dorm, let;
	long long int x;
	cin >> dorm >> let;
	vector<long long int> r, l;
	soma.pb(0);
	for (int i = 0; i < dorm; i++) {
		cin >> x;
		r.pb(x);
		
		soma.pb(soma[i]+x);
	}
	for (int i = 0; i < let; i++) {
		cin >> x;
		l.pb(x);
	}
	
	int pos;
	for (int i = 0; i < let; i++) {
		pos = lower_bound(soma.begin(), soma.end(), l[i]) - soma.begin();
		
		cout << pos << " " << l[i]-soma[pos-1] << endl;
	}
	
	
	return 0;
}
