#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int MAXM = 105, MAXS = 909;

int main() {
	int m, s, falta; scanf("%d%d", &m, &s);

	if (m == 1 && s == 0) return !printf("0 0\n");
	if (m != 1 && s == 0) return !printf("-1 -1\n");

	string men;
	falta = s;

	for (int k = 1; k <= m; k++) {
		for (int i = 0; i <= 9; i++) {
			if (k == 1 && i == 0) continue;

			if (falta-i >= 0 && falta-i <= (m-k)*9) {
				men += i+"0";
				falta -= i;
				break;
			}
		}
		if (men.size() < k) {
			men = "-1";
			break;
		}
	}

	string mai;
	falta = s;

	for (int k = 1; k <= m; k++) {
		for (int i = 9; i >= 0; i--) {
			if (k == 1 && i == 0) continue;

			if (falta-i >= 0 && falta-i <= (m-k)*9) {
				mai += i+"0";
				falta -= i;
				break;
			}
		}
		if (mai.size() < k) {
			mai = "-1";
			break;
		}
	}

	cout << men << " " << mai << endl;

}