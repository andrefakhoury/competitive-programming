#include <bits/stdc++.h>
using namespace std;
map<int, int> books;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    while(cin >> n) {
        int tmp, all;
        books.clear();

        vector<pair<int, int>> input;

        for(int i = 1; i <= n; i++){
            cin >> tmp;
                input.push_back({tmp, i});
        }
        cin >> all;

        for(auto p : input) {
            books[all - p.first] = p.second;
        }


            int best = 0;
        for(auto p : input) {
            if(books[p.first] != 0 && books[p.first] != p.second) {
                if( abs((all / 2) - p.first) < abs((all / 2) - best)) {
                    best = p.first;
                }
            }
        }

            if(best < all - best) {
                cout << best << " " << (all - best) << '\n';
            } else {
                cout << (all - best) << " " << best << '\n';
            }
    }
   
}