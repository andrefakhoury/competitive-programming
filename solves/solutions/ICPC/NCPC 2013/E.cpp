#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	auto l1 = a.begin(), l2 = b.begin(), r1 = a.end()-1, r2 = b.end()-1;

	while (l1 <= r1 and l2 <= r2) {
		if (*l1 == *l2) ++l1, ++l2;
		else if (*r1 == *r2) --r1, --r2;
		else break;
	}

	cout << r2 - l2 + 1 << "\n";

	return 0;
}