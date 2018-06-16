#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 100000
#define MAXM 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> edges[MAXN];
bool marked[MAXN];
int val[MAXN];

int n = 0, q, i, xx, yy;

long long prim(int x)
{
	mset(marked, 0);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int y;
    long long maximumCost = 0;
    pii p;
    pq.push(make_pair(0, x));
    while(!pq.empty())
    {
        // Select the edge with minimum weight
        p = pq.top();
        pq.pop();
        x = p;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        maximumCost += -abs(val[p]-val[]);
        marked[x] = true;
        for(int i = 0; i < edges[x].size();++i)
        {
            y = edges[x][i];
            if(marked[y] == false)
                pq.push(edges[x][i]);
        }
    }
    return maximumCost;
}

int main () {
	int t; scanf("%d", &t);

	while(t--) {
		mset(val, 0);

		for (int i = 0; i <= n; i++)
			edges[i].clear();
		for (int i = 1; i <= n; i++)
			val[i] = i;

		scanf("%d %d", &n, &q);
		
		while(q--) {
			scanf("%d", &i);
			if (i == 1) {
				scanf("%d %d", &xx, &yy);
				val[xx] = yy;
			}
			else {
				printf("%lld\n", -prim(1));
			}
		}

	}

	return 0;
}