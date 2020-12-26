#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

int a[MAXN];
char pos[MAXN];

int main() {
	int n; scanf("%d", &n);

	for (int i = 1; i <= n; i++) scanf("%d ", a+i);
	scanf("%s", pos+1);

	vector<pair<int, int> > ranges;
	for (int i = 1; i <= n; i++) {
		if (pos[i] == '0') continue;

		int j;
		for (j = i+1; j < n; j++)
			if (pos[j] == '0') break;

		ranges.push_back(make_pair(i, j));
		i = j+1;
	}

	for (int i = 0; i < (int)ranges.size(); i++) {
		int u = ranges[i].first;
		int v = ranges[i].second;
		sort(a+u, a+v+1);
	}

	for (int i = 1; i < n; i++)
		if (a[i] > a[i+1]) return !printf("NO\n");

	return !printf("YES\n");
}