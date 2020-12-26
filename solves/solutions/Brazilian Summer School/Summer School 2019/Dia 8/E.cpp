#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int a[MAXN], freq[MAXN];
set<int> change;
set<int> need;

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
		freq[a[i]]++;

		if (a[i] > n || freq[a[i]] > 1) {
			change.insert(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (freq[i] == 0) need.insert(i);
	}

	for (int i : change) {
		int next = *need.begin();
		need.erase(need.begin());

		a[i] = next;
	}

	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	printf("\n");
}