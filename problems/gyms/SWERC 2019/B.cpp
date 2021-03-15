#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

const int N = 1000007, inf = 0x3f3f3f3f;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    map<string, int> cnt;
    int n; cin >> n;

    for(int i = 0; i < n; ++i) {
        string s; cin >> s;

        cnt[s]++;
    }

    for(auto a : cnt) {
        int f = a.second;
        if(f > n - f) {
            cout << a.first << endl;
            return 0;
        }
    }

    cout << "NONE" << endl;
}