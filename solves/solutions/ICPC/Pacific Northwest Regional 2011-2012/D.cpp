#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e6 + 5;
vector<int> edges[MAXN];
int vis[MAXN];
vector<int> ts;

void topo(int u){
    vis[u] = 1;
    for(int v : edges[u]) if(!vis[v]) topo(v);
    ts.pb(u);
}

struct point{
    int x, y;
    
    point() {}

    point(int x, int y) : x(x), y(y) {}
    
    bool operator<(const point& b) const {
        if(x == b.x) return y < b.y;
        return x < b.x;
    }

    bool operator==(const point& b) const {
        return b.x == x and b.y == y;
    }

    int operator^(const point& b) const {
        return x*b.y - y*b.x;
    }
};

struct edge{
    point a, b;

    edge() {}

    edge(point a, point b) : a(a), b(b) {}

    bool operator<(const edge& e) const{
        if(a == e.a) return b < e.b;
        return a < e.a;
    }
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        
        for(int i = 0; i <= n; i++) edges[i].clear();
        for(int i = 0; i <= n; i++) vis[i] = 0;

        point p[3];

        map<edge, pair<int, point>> m;

        for(int i = 0; i < n; i++){
            int x1, y1, x2, y2, x3, y3;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

            p[0] = point(x1, y1);
            p[1] = point(x2, y2);
            p[2] = point(x3, y3);
            
            for(int j = 0; j < 3; j++){
                edge e = edge(p[j], p[(j+1)%3]);
                edge f = e;
                swap(f.a, f.b);
                if(m.count(e) or m.count(f)){
                    if(!m.count(e)) e = f;
                    point u = m[e].se;
                    point v = p[(j+2)%3];
                    int id = m[e].fi;

                    if(e.a.x == e.b.x) continue;

                    if(e.a.y == e.b.y){
                        if(u.y < v.y) edges[id].pb(i);
                        else edges[i].pb(id);
                        continue;
                    } 
                    
                    if(e.a.y > e.b.y)
                        swap(e.a, e.b);

                    ll dx = (e.a.x - e.b.x);
                    ll dy = (e.a.y - e.b.y);

                    ll A = dx;
                    ll B = -dy;
                    ll C = dy * e.a.x - dx * e.a.y;

                    if(dx < 0) {
                        if(A * u.y + B * u.x + C > 0){
                            edges[id].pb(i);
                        } else {
                            edges[i].pb(id);
                        }
                    } else { 
                        if(A * u.y + B * u.x + C < 0){
                            edges[id].pb(i);
                        } else {
                            edges[i].pb(id);
                        }
                    }
                } else {
                    m[e] = {i, p[(j+2)%3]};
                }
            }

        }

         //for(int i = 0; i < n; i++){
             ////cout << i + 1 << ": ";
             //for(int v : edges[i]) cout << v + 1 << " ";
             //cout << endl;
         //}

        ts.clear();
        for(int i = 0; i < n; i++){
            if(!vis[i]) topo(i);
        }

        reverse(ts.begin(), ts.end());

        for(int i : ts) cout << i + 1 << " ";
        cout << endl;
    }
	return 0;
}