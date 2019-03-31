#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define FF first
#define SS second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 5;

int a[MAXN];
int freq[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);
	
	int id = 1;
	for (int i = 1; i <= n; i++) {
		freq[a[i]]++;
		if (freq[a[i]] > freq[a[id]]) id = i;
	}

	int ans = n - freq[a[id]];

	printf("%d\n", ans);
	for (int i = id+1; i <= n; i++) {
		if (a[i] < a[i-1]) printf("1 %d %d\n", i, i-1);
		if (a[i] > a[i-1]) printf("2 %d %d\n", i, i-1);
		a[i] = a[i-1];
	}
	for (int i = id-1; i >= 1; i--) {
		if (a[i] < a[i+1]) printf("1 %d %d\n", i, i+1);
		if (a[i] > a[i+1]) printf("2 %d %d\n", i, i+1);
		a[i] = a[i+1];
	}

}