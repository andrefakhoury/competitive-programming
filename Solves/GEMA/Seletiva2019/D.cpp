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
 
void imp() {
    cout << "NO\n";
    exit(0);
}
void pos() {
    cout << "YES\n";
    exit(0);
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
 
    string s, t; cin >> s >> t;
 
    if (s.size() < t.size()) imp();
    
    int i, j;
    for (i = 0, j = 0; i < s.size(); i++) {
        j += s[i] == t[j];
        if (j == t.size()) pos();
    }
 
    imp();
 
    
 
    return 0;
}