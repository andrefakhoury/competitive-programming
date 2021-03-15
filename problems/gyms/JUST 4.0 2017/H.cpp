#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mk make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

char mat[55][55];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> mat[i][j];
            }
        }

        int qtt = 0;
        for (int j = 1; j <= m; j++) {
            qtt += mat[1][j] != '1';
            qtt += mat[n][j] != '1';
        }

        for (int i = 2; i <= n-1; i++) {
            qtt += mat[i][1] != '1';
            qtt += mat[i][m] != '1';
        }

        int pos = 0;
        for (int i = 2; i <= n-1; i++) {
            for (int j = 2; j <= m-1; j++) {
                pos += mat[i][j] == '1';
            }
        }

        if (qtt <= pos) cout << qtt << '\n';
        else cout << -1 << '\n';

        
    }

    

	return 0;
}