#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back

#define inf 0x3f3f3f3f
#define MAXN 100000
#define MAXM 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main () {
    ios::sync_with_stdio(false);
    
	int ans = 0;
	int r, g, b;
	
    cin >> r >> g >> b;
	
    ans = (r/2) + (g/2) + (b/2);

    cout << ans << endl;


    return 0;
}