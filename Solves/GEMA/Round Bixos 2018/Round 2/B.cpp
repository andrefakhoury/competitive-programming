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

    int n;
    cin >> n;

    int pot;

    for (pot = 1; pot < n;) {
        pot*=2;
    }

    int ans = 0;

    while(pot > 0 && n != 0) { 
		if (pot == 0) break;
        if (n-pot >= 0) {
            n = n-pot;
            ans++;
        }
        pot = pot/2;
    }

    cout << ans << endl;

    return 0;
}