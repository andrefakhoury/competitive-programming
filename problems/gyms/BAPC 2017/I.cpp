#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

const int N = 1007, inf = 0x3f3f3f3f;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
int P, Q; 

int memo[N][N][2];
bool vis[N][N][2];

int solve(int p, int q, int x) {
	if(p * q == 0) return 0;
	int & st = memo[p][q][x];

	if(vis[p][q][x] == 0) {
		vis[p][q][x] = 1;
		if(x == 0) {
			st = -inf;
			for(int k = 1; k <= q; k++) {
				if((p&1) and (k&1)) {
					if((Q - q)&1) st = max(st, -1 + solve(p, q - k, 1 - x));
					else st = max(st, 1 + solve(p, q - k, 1 - x));
				} else {
					st = max(st, solve(p, q - k, 1 - x));
				}
			}
		} else {
			st = inf;
			for(int k = 1; k <= p; k++) {
				if((q&1) and (k&1)) {
					if((Q - q + p - 1)&1) st = min(st, 1 + solve(p - k, q, 1 - x));
					else st = min(st, -1 + solve(p - k, q, 1 - x));
				} else {
					st = min(st, solve(p - k, q, 1 - x));
				}
			}
		}
	}

	return st;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> P >> Q;
    cout << solve(P, Q, 0) << endl;
}