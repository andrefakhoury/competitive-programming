#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e3 + 5, INF = 0x3f3f3f3f;

int n, k;
string s;

char cor(int b) {
    if (b == 0) return 'R';
    if (b == 1) return 'G';
    return 'B';
}

int cor(char c) {
    if (c == 'R') return 0;
    if (c == 'G') return 1;
    return 2;

}

int memo[MAXN][3];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	while(t--) {
		cin >> n >> k;
        cin >> s;
        
        memset(memo, 0, sizeof memo);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                memo[(j + i + 1)%3][i+1] = memo[(j + i)%3][i] + (s[i] != 'R');
            }
        }

        for (int c = 0; c < 3; c++) {
            for (int i = 0; i < n; i++) {

            }
        }

        
        
        

        cout << ans << '\n';
	}
	
	return 0;
}