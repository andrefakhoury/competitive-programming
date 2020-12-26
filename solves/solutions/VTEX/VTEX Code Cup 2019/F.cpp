#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e5 + 5;

int tin[MAXN], tout[MAXN];
int times[MAXN];

struct caixa {
	int a, b, c;
	caixa() {}
	caixa(int d, int e, int f) {
		int x, y, z;
		vector<int> aux = {d, e, f};
		sort(aux.begin(), aux.end());

		x = aux[0], y = aux[1], z = aux[2];

		a = x, b = y, c = z;
	}

	bool operator<(caixa outra) {
		if (a == outra.a) {
			if (b == outra.b) {
				return c < outra.c;
			} else {
				return b < outra.b;
			}
		} else {
			return a < outra.a;
		}
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	vector<caixa> a;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, z; cin >> x >> y >> z;
		a.emplace_back(x, y, z);
	}

	sort(a.begin(), a.end());

	for (int i = 1; i < n; i++) {
		caixa c1 = a[i];
		caixa c2 = a[i-1];

		if (c1.a <= c2.a || c1.b <= c2.b || c1.c <= c2.c) {
			cout << 'N' << endl;
			return 0;
		}
	}

	cout << 'S' << endl;
	return 0;
}