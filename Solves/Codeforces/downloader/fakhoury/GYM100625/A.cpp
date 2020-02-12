#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 1e5 + 5;
 struct Car {
    ll catalog, pick, costperk;
     void read() {
        cin >> catalog >> pick >> costperk;
    }
};
 struct Agent {
    int curCar, pickTime;
    ll price;
    bool consistent;
     Agent() {
        curCar = -1, pickTime = -1;
        price = 0;
        consistent = true;
    }
     void pickCar(int ind, int h, long long cost) {
        if (curCar != -1) {
            consistent = false;
        } else {
            curCar = ind;
            pickTime = h;
            price += cost;
        }
    }
     void returnCar(int h, int km, map<int, Car>& cars) {
        if (h <= pickTime || curCar == -1) consistent = false;
        else {
            price += cars[curCar].costperk * km;
            curCar = -1;
            pickTime = -1;
        }
    }
     void accident(int pc, map<int, Car>& cars) {
        if (curCar == -1) {
            consistent = false;
        } else {
            price += (pc * cars[curCar].catalog + 99) / 100;
        }
    }
};
 int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
     int T; cin >> T;
    while(T--) {
        map<string, int> mpCar;
         map<int, Car> cars;
        map<string, Agent> agents;
         int n, q; cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            string s; cin >> s;
             mpCar[s] = i;
            cars[i].read();
        }
         while(q--) {
            int h; cin >> h;
            string ag; cin >> ag;
            char op; cin >> op;
             if (op == 'p') {
                string x; cin >> x;
                int ind = mpCar[x];
                agents[ag].pickCar(ind, h, cars[ind].pick);
            } else if (op == 'r') {
                int d; cin >> d;
                agents[ag].returnCar(h, d, cars);
            } else {
                int pc; cin >> pc;
                agents[ag].accident(pc, cars);
            }
        }
         for (auto ag : agents) {
            cout << ag.fi << " ";
            if (ag.se.consistent && ag.se.curCar == -1) cout << ag.se.price;
            else cout << "INCONSISTENT";
            cout << '\n';
        }     
    }
     return 0;
}