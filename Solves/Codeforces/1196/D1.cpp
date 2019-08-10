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

char pegaochar(int b) {
    if (b == 0) return 'R';
    if (b == 1) return 'G';
    return 'B';
}

string get(int b) {
    string ret;
    for (int i = 0; i < k; i++) {
        ret += pegaochar(b);
        b++; b %= 3;
    }
    return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	while(t--) {
		cin >> n >> k;
        cin >> s;
        
        int ans = INF;

        for (int jj = 0; jj < 3; jj++) {
            string t = get(jj);

            for (int i = 0; i <= n - k; i++) {

                int cur = 0;

                for (int j = 0; j < k; j++) {
                    if (s[i+j] != t[j]) cur++;
                }

                ans = min(ans, cur);
            }
        }

        cout << ans << '\n';
	}
	
	return 0;
}