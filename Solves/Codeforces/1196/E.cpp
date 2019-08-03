#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

struct PT {
    int x, y;

    PT() {}
    PT(int a, int b) {
        x = a, y = b;
    }

    bool operator< (PT p) {
        return p.x == x ? x < p.y : x < p.x;
    }
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	while(t--) {
		int b, w; cin >> b >> w;
        int B = b, W = w;

        vector<PT> ans;

        if (b < w) {
            int last = 0;
            for (int i = 3; b > 0 && w > 0; i++) {
                ans.eb(i, 2);

                b -= i%2 != 0;
                w -= i%2 == 0;

                last = i;
            }

            if (w > 0) {
                w--;
                ans.eb(2, 2);
            }

            if (w > 0) {
                w--;
                ans.eb(last + 1, 2);
            }

            for (int x = 3; x <= last && w > 0; x += 2) {
                w--;
                ans.eb(x, 1);
            }

            for (int x = 3; x <= last && w > 0; x += 2) {
                w--;
                ans.eb(x, 3);
            }          
        } else {
            int last = 0;
            for (int i = 2; b > 0 && w > 0; i++) {
                ans.eb(i, 2);
                b -= i%2 != 0;
                w -= i%2 == 0;
                last = i;
            }

            if (b > 0) {
                b--;
                ans.eb(1, 2);
            }

            if (b > 0) {
                b--;
                ans.eb(last + 1, 2);
            }

            for (int x = 2; x <= last && b > 0; x += 2) {
                b--;
                ans.eb(x, 1);
            }

            for (int x = 2; x <= last && b > 0; x += 2) {
                b--;
                ans.eb(x, 3);
            }            
        }

        if (b > 0 || w > 0 || ((int)ans.size() != B + W)) cout << "NO\n";
        else {
            sort(ans.begin(), ans.end());

            cout << "YES\n";
            for (PT p : ans) {
                cout << p.x << ' ' << p.y << '\n';
            }
        }
	}
	
	return 0;
}