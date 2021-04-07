#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 3e5 + 5;

int n;
vector<int> edges[MAXN]; // arestas originais
vector<int> revEdges[MAXN]; // grafo reverso
vector<int> sccEdges[MAXN]; // grafo condensado

int color[MAXN]; // qual componente o cara ta
vector<int> sameColor[MAXN]; // quais caras tao nessa componente

vector<int> order;
void dfsOrder(int u) {
	color[u] = 1; // visitado
	for (int v : edges[u]) if (!color[v]) {
		dfsOrder(v);
	}
	order.push_back(u);
}

void dfsColor(int u, int c) {
	color[u] = c;
	sameColor[c].push_back(u); // assume o cara na componente
	for (int v : revEdges[u]) if (!color[v]) {
		dfsColor(v, c); // chama os vizinhos para colorir
	}
}

inline void kosaraju() {
	// pega a ordem
	memset(color, 0, sizeof color);
	for (int u = n; u >= 1; u--) {
		if (!color[u]) dfsOrder(u);
	}
	reverse(order.begin(), order.end());

	// monta as componentes
	memset(color, 0, sizeof color);
	int curColor = 0;
	for (int u : order) {
		printf("%d ", u);
		if (!color[u]) {
			dfsColor(u, ++curColor);
		}
	}
	puts("");

	// monta o grafo condensado
	for (int c = 1; c <= curColor; c++) {
		for (int u : sameColor[c]) {
			for (int v : edges[u]) {
				sccEdges[c].push_back(color[v]);
			}
		}
	}

	// "limpa" as arestas repetidas (opcional)
	for (int c = 1; c <= curColor; c++) {
		sort(sccEdges[c].begin(), sccEdges[c].end());
		sccEdges[c].erase(unique(sccEdges[c].begin(), sccEdges[c].end()), sccEdges[c].end());

		printf("%d: ", c);
		for (int x : sameColor[c]) printf("%d ", x);
		puts("");
	}
}

int main() {
	int m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		revEdges[v].push_back(u);
	}

	kosaraju();
}