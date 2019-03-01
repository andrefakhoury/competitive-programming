#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	
	long long sum = 0;
	for (int i = 0, j = n-1; i < j; i++, j--) {
		sum += (a[i] + a[j])*(a[i] + a[j]);
	}
	
	cout << sum << endl;
	
	
	
	return 0;
}