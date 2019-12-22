#include <bits/stdc++.h>
using namespace std;

struct vertex {
    long long x, y;
    double dist = DBL_MAX;

    bool operator==(vertex const& v) const{
        return v.x == x && v.y == y;
    }

    bool operator<(vertex const& v) const {
        if(v.x == x) return y < v.y;
        else return x < v.x;
    }
};

vector<vertex> vertexes;
map<vertex, vector<vertex>> edges;
map<vertex, bool> seen;

double get_dist(vertex a, vertex b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, sz = 0;
    while(cin >> n, n) {
        
        // clear structures
        vertexes.clear();
        edges.clear();
        seen.clear();

        // read vertexes
        int x, y;
        while(n--){
            cin >> x >> y;
            vertexes.push_back({x, y});
        }

        vertex start = vertexes[0], last = vertexes[1];
/*        
        // get max jump distance
        long long max_dist = get_dist(start, last);
*/
        double dist;

        // construct graph
        for(int i = 0; i < vertexes.size(); i++){
            for(int k = 0; k < vertexes.size(); k++){

                // no self-loops 
                if(get_dist(vertexes[i], vertexes[k]) == 0) continue;
/*
                // no jumps which are longer than the max dist
                if(max_dist <= dist) continue;
*/
                // add the edges
                edges[vertexes[i]].push_back(vertexes[k]);
                edges[vertexes[k]].push_back(vertexes[i]);
            }
        }
        
        // vertex with smallest current state on top
        auto comp = [] (auto v1, auto v2) { return v1.dist > v2.dist; };
        priority_queue<vertex, vector<vertex>, decltype(comp)> todo(comp); 

        // put start node in there
        start.dist = 0;
        todo.push(start);

        // find shortest path
        vertex curr;
        while(!todo.empty()) {

            // get next vertex
            curr = todo.top();
            todo.pop();

            // already seen this vertex
            if(seen[curr]) continue;
            seen[curr] = true;

            if(curr == last) break;
 //           cout << "curr: " << curr.x << " " << curr.y << " last: " << last.x << " " << last.y << endl;

            for(vertex reach : edges[curr]) {

                // distance to the next vertex
                dist = max(curr.dist, get_dist(curr, reach));
/*
                cout << "curr: " << curr.x << " " << curr.y << " reach: " << reach.x 
                     << " " << reach.y << " dist: " << dist << " reach.dist: " << reach.dist<< endl;
      */          
                // update if first visit of vertex or better distance
                if(dist < reach.dist) {
                    reach.dist = dist;
                    todo.push(reach);
                }
            }
        }

        sz++;
        cout << "Cenario #" << sz << '\n';
        cout << fixed << setprecision(3) << "Distancia de Salto = " << curr.dist << '\n';
    }
    
   
}