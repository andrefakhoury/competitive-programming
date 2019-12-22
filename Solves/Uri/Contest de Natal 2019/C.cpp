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
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const long double lambda = 700;
const long double c = 3e8;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	long double v; cin >> v;
	long double l1 = (sqrt((c-v)/(c+v)) - 1) * lambda + lambda;
	l1 -= 1e-12;

	if (l1 < 400) cout << "invisivel\n";
	else if (l1 < 425) cout << "violeta\n";
	else if (l1 < 445) cout << "anil\n";
	else if (l1 < 500) cout << "azul\n";
	else if (l1 < 575) cout << "verde\n";
	else if (l1 < 585) cout << "amarelo\n";
	else if (l1 < 620) cout << "laranja\n";
	else if (l1 < 750) cout << "vermelho\n";
	else cout << "invisivel\n";

	return 0;
}