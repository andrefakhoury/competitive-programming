#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc <= 300) {
		int n; scanf("%d", &n);
		return main(n + 300, argv);
	} else {
		return !printf("%d\n", 1 + (argc == 302));
	}
}
