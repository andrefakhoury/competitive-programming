#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n;

	vector<int> qtdes;
	vector<int> soma;

	int combo1 = 0, combo2 = 0, posc1 = 0, posc2 = 0;

	string pessoa;

	int a;

	cin >> n;
	for (a = 0; a<n; a++) {
		cin >> pessoa;
		qtdes.push_back(pessoa.size());
	}

	sort(qtdes.begin(), qtdes.end());

	for (a = 0; a<n; a++) {
		if (a==0) {
			combo1 = 1;
			posc1 = qtdes[a];
		} else {
			if (qtdes[a] == qtdes[a-1]) {
				if (posc1 == qtdes[a]) combo1++;
				else if (posc2 == qtdes[a]) combo2++;
				else { combo2 = 1; posc2 = qtdes[a]; }
			}

			if (combo2 >= combo1) {
				combo1 = combo2;
				posc1 = posc2;

				combo2 = 0;
				posc2 = 0;
			}
		}
	}

	cout << posc1 << "\n";

	return 0;
}