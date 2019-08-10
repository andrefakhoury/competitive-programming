#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
#define MAXN 100005

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	long long a, b, c; cin >> a >> b >> c;
	long long resto = abs(a - b) > 0;

	cout << (2ll * c + 2ll * min(a, b) + resto) << endl;
}