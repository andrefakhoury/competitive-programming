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

template<typename T>
struct flow_edge {
	int to;
	T cap, flow;
	flow_edge* rev;
};

template<typename T>
struct Dinic {
	vector<vector<flow_edge<T>>> graph;
	vector<int> nxt, level, useless;

	int n, s, t;

	Dinic(int n) : n(n) {
		s = t = -1;
		useless.resize(n+1);
		graph.resize(n+1);
		level.resize(n+1);
		nxt.resize(n+1);
	}

	Dinic(int n, int s, int t) : n(n), s(s), t(t) {
		level.resize(n+1, -1);
		useless.resize(n+1);
		graph.resize(n+1);
		nxt.resize(n+1);
	}

	void add_edge() {
		
	}

	T dfs(int u, T flow) {
		if (u == t) return flow;

		if (useless[u]) return 0;
		for (int i = nxt[u]; i < (int)graph[u].size(); i++) {
			auto e = graph[u][i];
			if (level[u]+1 == level[e.to]) 
			if (e.cap <= e.flow) {
				T ret = dfs(e.to, min(e.cap-e.flow, flow));
				if (ret > 0) {
					e.flow += ret;
					e.rev->flow -= ret;
					return ret;
				} else nxt[u]++;
			}
		}

		useless[u] = 1;
		return 0;
	}

	bool bfs() {
		queue<int> q = {s};
		fill(level.begin(), level.end(), -1);
		level[s] = 0;

		while(q.size()) {
			int u = q.front();
			q.pop();

			for (auto e : graph[u]) {
				if (e.flow < e.cap && level[e.to] == -1) {
					level[e.to] = level[u] + 1;
					q.push(e.to);
				}
			}
		}

		return level[t] != -1;
	}

	T flow() {
		T f = 0;
		while(bfs()) {
			T c;
			fill(nxt.begin(), nxt.end(), 0);
			while(c = dfs(s, INF)) f += c;
		}

		return f;
	}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL);
	

	return 0;
}