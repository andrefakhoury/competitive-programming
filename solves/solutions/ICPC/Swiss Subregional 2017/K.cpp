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
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s;
    cin >> s;

    if (s.find("ACM") != s.npos) {
    	cout << "Fun!\n";
    }
    else cout << "boring...\n";

    return 0;
}