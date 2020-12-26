	#include <bits/stdc++.h>
using namespace std;

int CeilIndex(vector<int>& v, int l, int r, int key) {

	while (r - l > 1) {
		int m = l + (r - l) / 2;
		if (v[m] >= key) r = m;
		else l = m;
	}

	return r;
}

int lis(vector<int>& v) {
	if (v.size() == 0)
		return 0;

	std::vector<int> tail(v.size(), 0);
	int length = 1;

	tail[0] = v[0];
	for (size_t i = 1; i < v.size(); i++) {
		if (v[i] < tail[0])
			tail[0] = v[i];
		else if (v[i] > tail[length - 1])
			tail[length++] = v[i];
		else
			tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
	}

	return length;
}

int LIS(vector<int>& a, int i, int j) {
	if (i < 0) return 0;

	vector<int> aux;
	while (i <= j) aux.push_back(a[i++]);
	return lis(aux);
}

int SIL(vector<int>& a, int i, int j) {

	vector<int> aux;
	while (j >= i) aux.push_back(a[j--]);
	return lis(aux);
}

int main() {
	int n; scanf("%d", &n);
	vector<int> a(n);

	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	int ans = 0;
	for (int i = -1; i < n; i++) {
		int cur = 1 + LIS(a, 0, i) + SIL(a, i+1, n-1);
		ans = max(ans, cur);
	}

	printf("%d\n", ans);
}