#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG false
#define ll long long
typedef pair<int, int> pii;
 
const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 5;

bool won(int a, int b, int c) {
	return a != b && a != c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int a, b, c; cin >> a >> b >> c;
    if (won(a, b, c)) cout << 'A' << endl;
    else if (won(b, a, c)) cout << 'B' << endl;
    else if (won(c, b, a)) cout << 'C' << endl;
    else cout << '*' << endl;
 
    return 0;
}