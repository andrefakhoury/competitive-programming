#include <bits/stdc++.h>
using namespace std;
map<int, int> books;

struct house{
    int x, y, height, max_length;
};

// {x, y} -> max length
map<pair<int, int>, house> houses; 

int max_length;

void update_next_house(pair<int, int> curr, pair<int,int> next){ 

    // update the max length
    max_length = max(max_length, houses[curr].max_length);

    // next house to high
    if(houses[curr].height < houses[next].height){

        // update next house
        houses[next].max_length = max(houses[next].max_length, houses[curr].max_length + 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int q;
    cin >> q;
    while(q--) {
        string name;
        int l, c, tmp;
        cin >> name >> l >> c;
        houses.clear();
        max_length = 0;

        // do the houses with lower height first
        auto comp = [](house p1, house p2) { return p1.height > p2.height; };
        priority_queue<house, vector<house>, decltype(comp)> todo(comp);

        // read input
        for(int i = 0; i < l; i++){
            for(int k = 0; k < c; k++){
                cin >> tmp;
                todo.push({i, k, tmp, 1});
                houses[{i, k}] = {i, k, tmp, 1};
            }
        }

        max_length = 0;
        pair<int, int> curr;
        house h;

        // check where you can go with the lower houses
        while(!todo.empty()) {
            
            // get smallest house
            h = todo.top();
            todo.pop();
            curr = {h.x, h.y};

            // left
            if(0 < h.x) {
                update_next_house(curr, {h.x - 1, h.y});
            }
            // down
            if(0 < h.y) {
                update_next_house(curr, {h.x, h.y - 1});
            }
            // right
            if(h.x + 1 < l) {
                update_next_house(curr, {h.x + 1, h.y});
            }
            // up
            if(h.y + 1 < c) {
                update_next_house(curr, {h.x, h.y + 1});
            }
        }

        // we start with length 0 instead of 1
        cout << name << ": " << max_length  << '\n';
    }
   
}