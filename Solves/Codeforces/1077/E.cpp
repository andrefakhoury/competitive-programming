#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define pb push_back

int n;
map<int, int> prob;

int main() {
	scanf("%d", &n);
	int x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		prob[x]++;
	}
	vector<int> freq;
	for (auto it = prob.begin(); it != prob.end(); it++)
		freq.pb(it->second);
	sort(freq.begin(), freq.end(), greater<int>());

	int num = freq[0] - (freq[0]%2);
	int ans = 0;
	for (int k = num; k > 0; k -= 2) {
		int numt = k, curAns = k;
		for (int i = 1; i < freq.size(); i++) {
			if (numt%2) break;
			if (freq[i] < numt/2.0) break;
			curAns += numt/2;
			numt /= 2;
		}
		ans = max(ans, curAns);		
	}

	ans = max(ans, freq[0]);

	printf("%d\n", ans);	
}