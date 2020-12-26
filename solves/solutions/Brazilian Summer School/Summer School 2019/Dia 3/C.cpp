#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 10000;
const int INF = 0x3f3f3f3f;

int n, m;
map<char, int> alpha;
map<int, char> volta;

vector<int> edges[MAXN];
vector<char> input[MAXN];
map<pair<int, int>, string> memo;

string IMP = "ZZZZZ";

string dfs(int at, int mask) {
	// string binary = std::bitset<15>(mask).to_string(); //to binary
 //    cout << at << " : " << binary << endl;

	if (memo.count(mp(at, mask))) return memo[mp(at, mask)]; 

	if ((mask & (1 << at))) return memo[mp(at, mask)] = IMP; //ja foi visitado

	mask |= 1 << at;

	string s = ""; s.pb(volta[at]);

	if (at == n-1 && mask == (1 << n) - 1) return s;
	else if (at == n-1) return memo[mp(at, mask)] = IMP;

	for (int i = 0; i < (int)edges[at].size(); i++) {
		int v = edges[at][i];

		if ((mask & (1 << v))) continue;

		string op = dfs(v, mask);
		if (op != IMP) return memo[mp(at, mask)] = s + op;
	}

	return memo[mp(at, mask)] = IMP;	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	int caso = 1;
	while(T--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			char c; cin >> c;
			alpha[c] = i;
			volta[i] = c;
		}

		for (int i = 1; i <= m; i++) {
			char u, v; cin >> u >> v;
			input[alpha[u]].pb(v);
			input[alpha[v]].pb(u);
		}

		for (int i = 0; i < n; i++) {
			sort(input[i].begin(), input[i].end());
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (int)input[i].size(); j++)
				edges[i].pb(alpha[input[i][j]]);
		}

		string ans = dfs(0, 0);

		cout << "Case " << caso << ": " << ((ans == IMP) ? "impossible" : ans) << "\n";

		for (int i = 0; i < n; i++) {
			edges[i].clear();
			input[i].clear();
		}
		volta.clear();
		alpha.clear();

		caso++;
	}

	return 0;
}