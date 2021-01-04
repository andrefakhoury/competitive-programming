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
const int INF = 0x3f3f3f3f;

vector<string> limpa(string s) {
    vector<string> vec;

    string t;
    for (char c : s) {
        if (c == ' ' || c == ',' || c == '.' || c == '!' || c == ';'
            || c == '?' || c == '(' || c == ')' || c == ':') {
                if (t.size()) vec.push_back(t);
                t = "";
                continue;
            }

        t += tolower(c);
    }

    if (t.size())
        vec.push_back(t);

    return vec;
}

int main() {
    ios::sync_with_stdio(false);

    int n; cin >> n;

    map<string, string> mp;

    for (int i = 0; i < n; i++) {
        string lang; cin >> lang;

        string s; getline(cin, s);
        vector<string> vec = limpa(s);
        for (string& x : vec) mp[x] = lang;
    }

    string s;

    cin.ignore();

    while (getline(cin, s)) {
        vector<string> vec = limpa(s);
        string ans;

        for (string& x : vec) {
            if (mp.count(x) && x.size() && mp[x].size()) ans = mp[x];
        }  

        cout << ans << '\n';
    }

    return 0;
}