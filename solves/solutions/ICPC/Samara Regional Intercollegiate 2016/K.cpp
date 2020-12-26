#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fastcin ios::sync_with_stdio(false); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

string s;

bool go(int i, int j) {
    for (; i < j; i++, j--) {
        if (s[i] != s[j]) return false;
    }

    return true;
}

void imp() {
    cout << "NO\n";
    exit(0);
}

int main(){
    fastcin;
    
    cin >> s;
    
    int ans = -1;

    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            if (go(i+1, j)) {
                ans = i+1;
                break;   
            } else if (go(i, j-1)) {
                ans = j+1;
                break;
            } else imp();
        }
    }

    if (ans == -1) {
        cout << "YES\n" << s.size()/2 + 1<< endl;
    } else {
        cout << "YES\n" << ans << endl;
    }

    return 0;
}