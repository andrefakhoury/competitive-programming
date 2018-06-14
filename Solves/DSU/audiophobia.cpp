#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 10000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> edges[MAXN];
bool marked[MAXN];

long long prim(int x)
{
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    int y;
    long long minimumCost = 0;
    pii p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < edges[x].size();++i)
        {
            y = edges[x][i].second;
            if(marked[y] == false)
                Q.push(edges[x][i]);
        }
    }
    return minimumCost;
}


int main () {
    int c, s, q, c1, c2, d, q1, q2;
    long long ans;
    scanf("%d%d%d", &c, &s, &q);
    while (c != 0 && s != 0 && q != 0) {
    	memset(marked, 0, sizeof(marked));
		for (auto& v : edges) v.clear();

    	for (int i = 0; i < s; i++) {
    		scanf("%d%d%d", &c1, &c2, &d);
    		edges[c1].pb({d, c2});
    		edges[c2].pb({d, c1});
    	}

    	for (int i = 0; i < q; i++) {
    		scanf("%d %d", &q1, &q2);
    		ans = 
    	}


    	scanf("%d%d%d", &c, &s, &q);
    }

    return 0;
}