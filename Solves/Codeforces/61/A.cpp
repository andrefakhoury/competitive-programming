#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
	string a, b; cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
		a[i] = ((a[i]-"0") xor (b[i]-"0")) + "0";
	cout << a << endl;
}