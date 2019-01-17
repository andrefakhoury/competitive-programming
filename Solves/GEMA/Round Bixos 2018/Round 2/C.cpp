#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back

#define inf 0x3f3f3f3f
#define MAXN 1000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main () {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    int ans = 0;
	
	int pot = 1;
	for (int i = 0; i < max(n, m); i++) {
		if (((n >> i) & 1) != ((m >> i) & 1))
			ans += pot;
		pot *= 2;
	}
	
	cout << ans << endl;

    return 0;
}