#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

struct Robot {
    int x, y, fL, fU, fR, fD;

    void read() {
        scanf("%d%d%d%d%d%d", &x, &y, &fL, &fU, &fR, &fD);
    }

    bool U() { return fU; }
    bool D() { return fD; }
    bool R() { return fR; }
    bool L() { return fL; }
};

int main() {
    const int LIM = 1e5;

	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);

        vector<Robot> robots(n);
        for (int i = 0; i < n; i++) robots[i].read();

        int xm, xM, ym, yM;
        xm = ym = -LIM;
        xM = yM = LIM;

        bool ans = true;

        for (Robot rob : robots) {
            if (!rob.D()) {
                if (yM < rob.y) {
                    ans = false;
                    goto PRINT;
                } else {
                    ym = max(ym, rob.y);
                }
            }

            if (!rob.U()) {
                if (ym > rob.y) {
                    ans = false;
                    goto PRINT;
                } else {
                    yM = min(yM, rob.y);
                }
            }

            if (!rob.L()) {
                if (xM < rob.x) {
                    ans = false;
                    goto PRINT;
                } else {
                    xm = max(xm, rob.x);
                }
            }

            if (!rob.R()) {
                if (xm > rob.x) {
                    ans = false;
                    goto PRINT;
                } else {
                    xM = min(xM, rob.x);
                }
            }
        }

        PRINT:
        if (ans) {
            printf("1 %d %d\n", xm, ym);
        } else {
            printf("0\n");
        }
	}
	
	return 0;
}