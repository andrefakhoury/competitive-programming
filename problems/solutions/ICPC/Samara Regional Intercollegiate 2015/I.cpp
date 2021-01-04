#include <bits/stdc++.h>
    
#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define mk make_pair
    
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
    
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int x, y; cin >> x >> y;
    string move; cin >> move;
    int n; cin >> n;

    vector<string> names(n);
    vector<ll> ans(n);
    int best = 0;

    for (int i = 0; i < n; i++) {
        cin >> names[i];
        int X, Y; cin >> X >> Y;

        if (move[0] == 'L') {
            ans[i] = (abs(y-Y)+1)/2;
            int xx = x - ans[i];
            if (X < xx) ans[i] += (abs(X - xx) + 2) / 3;
            else ans[i] += abs(X - xx);
        } else if (move[0] == 'R') {
            ans[i] = (abs(y-Y)+1)/2;
            int xx = x + ans[i];
            if (X > xx) ans[i] += (abs(X - xx) + 2) / 3;
            else ans[i] += abs(X - xx);
        } else if (move[0] == 'U') {
            ans[i] = (abs(x-X)+1)/2;
            int yy = y + ans[i];
            if (Y > yy) ans[i] += (abs(Y - yy) + 2) / 3;
            else ans[i] += abs(Y - yy);
        } else if (move[0] == 'D') {
            ans[i] = (abs(x-X)+1)/2;
            int yy = y - ans[i];
            if (Y < yy) ans[i] += (abs(Y - yy) + 2) / 3;
            else ans[i] += abs(Y - yy);
        }

        if (ans[i] < ans[best]) best = i;
    }

    cout << names[best] << endl;
    

    return 0;
}