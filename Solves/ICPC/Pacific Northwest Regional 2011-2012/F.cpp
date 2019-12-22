#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

int main() {
    int t; cin >> t;
    while (t--) {
        int m; cin >> m;
        vector <int> fakhoury;
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            fakhoury.pb(x);
        }
        int cycle = 0;
        while (fakhoury.size() > 1) {
            bool prexa = false;
            for (auto f : fakhoury)
                if (f) prexa = true;
            if (!prexa) break;
            cycle++;
            for (int i = 1; i < fakhoury.size(); i++)
                fakhoury[i-1] = fakhoury[i] - fakhoury[i-1];
            fakhoury.erase(--fakhoury.end());
        }
        bool ok = false;
        int cur = fakhoury[0];
        if (!fakhoury[0]) {
            for (int j = 0; j < cycle; j++) cout << 'z';
            cout << "ap!\n";
            ok = true;
        } else if (!ok && cur > 0) cout << "*fizzle*\n";
        else if (!ok && cur < 0) cout << "*bunny*\n";
    }
	return 0;
}
 