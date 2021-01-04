#include <bits/stdc++.h>

#define deb(x) (cout << #x << ": " << x << endl)
#define pb push_back
#define fi first
#define se second
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int N = 107;
void no() {
	cout << "N" << endl;
	exit(0);
}
int mat[N][N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;

	for(int i = 1; i <= n; ++i) {
		int d, l, r, c; cin >> d >> l >> r >> c;

		if(d == 0) {
			if(c + l - 1 > 10) no();
			for(int k = c; k < c + l; ++k) {
				if(mat[r][k] > 0) {
					no();
				}
				mat[r][k] = i; 
			}
		} else {
			if(r + l - 1 > 10) no();

			for(int k = r; k < r + l; ++k) {
				if(mat[k][c] > 0) no();
				mat[k][c] = i;
			}
		}
	}

	cout << "Y" << endl;
}