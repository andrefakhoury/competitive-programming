#include <bits/stdc++.h>
using namespace std;

const long double EPS = 1e-9;

long double dist(long double x1, long double y1, long double x2, long double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1-y2));
}

long long read() {
    long long a, b;
    scanf("%lld.%lld", &a, &b);
    a = a * 1000 + b;
    return a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    while(cin >> n) {
        long double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1e4;
        y1 += 1e4;
        x2 += 1e4;
        y2 += 1e4;

        bool ok = false;
        while(n--) {
            long double x, y;
            cin >> x >> y;
            x += 1e4;
            y += 1e4;

            long double t1 = dist(x, y, x1, y1);
            long double t2 = dist(x, y, x2, y2) / 2.0;

            if (ok) continue;

            if (t1 < t2 + EPS) {
                x -= 1e4;
                y -= 1e4;
                cout << fixed << setprecision(3) << "O larapio consegue escapar pelo ponto de fuga (" << x << ", " << y << ").\n";
                ok = true;
            }
        }

        if (!ok) cout << "O larapio nao consegue escapar.\n";
    }
    

}