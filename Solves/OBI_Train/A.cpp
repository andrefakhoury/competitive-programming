#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 100000
#define MAXM 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int solve(int x) {
	int ans1 = 0, ans2 = 0, a = x;
	string s;
	while(x%6) {
		x/=10; ans1++;
		if (!x) ans1 = -1;
	}
	x = a;
	while(x%6) {
		s = to_string(x);
		s.erase(s.begin());
		x = stoi(s);
		ans2++;
	}
	if (ans1 != -1 && ans2 != -1) return (ans1 < ans2) ? ans1 : ans2;
	if (ans1 != -1 && ans2 == -1) return ans1;
	if (ans1 == -1 && ans2 != -1) return ans2;
	return -1;	
}

int main () {
	//ios::sync_with_stdio(false);
	int n, x, ans; scanf("%d", &n);
	while(n--) {
		scanf("%d", &x);
		ans = solve(x);
		if (ans == -1) printf("Cilada\n");
		else printf("%d\n", ans);
	}


	return 0;
}