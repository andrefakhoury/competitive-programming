#include <vector>
#include <iostream>
using namespace std;

#define eb emplace_back

struct Event {
    char op;
    int dist, newVal;

    Event() { }
    Event(char a, int b, int c) {
        op = a, dist = b, newVal = c;
    }
};

vector<Event> road;

bool check(double tank) {
    double original = tank;

    int leaking = 0;
    double loss = 0;

    int last = 0;
    for (Event ev : road) {
        int cur = ev.dist;

        tank -= (cur - last) / 100.0 * loss;
        if (leaking > 0) {
            tank -= leaking * (cur - last);
        }

        if (tank < 0) return false;

        if (ev.op == 'F') loss = ev.newVal;
        if (ev.op == 'L') leaking++;
        if (ev.op == 'M') leaking = 0;
        if (ev.op == 'P') tank = original;

        last = cur;

        if (tank < 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout.precision(3);
    cout << fixed;

    int d;
    string op;

    while(cin >> d >> op) {
        road.clear();

        if (d == 0 && op == "Fuel") {
            cin >> op >> d;
            if (op == "consumption" && d == 0) exit(0);
        }

        road.eb('F', 0, d);

        while(cin >> d >> op) {
            if (op == "Goal") {
                road.eb('G', d, -1);
                break;
            }

            if (op == "Fuel") {
                int newVal; 
                cin >> op >> newVal;
                road.eb('F', d, newVal);
            }

            if (op == "Leak") {
                road.eb('L', d, -1);
            }

            if (op == "Mechanic") {
                road.eb('M', d, -1);
            }

            if (op == "Gas") {
                road.eb('P', d, -1);
                cin >> op;
            }
        }

        double lo = 0, hi = 1e14, mi;
        int cnt = 5000;

        while(cnt--) {
            mi = (lo + hi) / 2.0;

            if (check(mi)) hi = mi;
            else lo = mi;
        }

        cout << hi << '\n';
    }    
}