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
    int n; cin >> n;
    getchar();
    while (n--) {
        string s;
        getline(cin, s);
        int cnt[300] = {0};
        for (int i = 0; i < s.size(); i++) cnt[tolower(s[i])]++;
        string ans;
        if (cnt['g'] == cnt['b']) ans = "NEUTRAL";
        else if (cnt['g'] > cnt['b']) ans = "GOOD";
        else ans = "A BADDY";
        cout << s << " is " << ans << endl;
    }
 return 0;
}