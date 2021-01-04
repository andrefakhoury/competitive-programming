#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e4 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	map<char, int> mp;
	for (int i = 0; i < 128; i++) mp[i] = i;
	mp['@'] = 'a', mp['&'] = 'e',
	mp['!'] = 'i', mp['*'] = 'o', mp['#'] = 'u';

	char c;
	while(~scanf("%c", &c)) printf("%c", mp[c]);
	printf("\n");
}