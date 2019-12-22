#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int n;
	while (scanf("%d ", &n), n) {
		map<string, int> freq;
		int maxi = 0;
		for (int i = 1; i <= n; i++) {
			int act[10];
			for (int i = 0; i < 5; i++) scanf("%d", &act[i]);
			sort(act, act+5);

			string rep = "";
			for (int i = 0; i < 5; i++)
				rep += to_string(act[i]);

			freq[rep]++;
			maxi = max(maxi, freq[rep]);
		}

		int ans = 0;
		for (auto it : freq) {
			if (it.second == maxi) {
				ans += it.second;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}