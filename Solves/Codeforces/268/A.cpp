#include <bits//stdc++.h>

using namespace std;

struct uniforme {
	int home, guest;
};


uniforme uni[100];

int main() {
	int n;

	int ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> uni[i].home >> uni[i].guest;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (uni[i].guest == uni[j].home) ans++;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (uni[j].guest == uni[i].home) ans++;
		}
	}


	cout << ans << endl;
	return 0;
}