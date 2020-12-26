#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

char mat[500][500];

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL);

    int n = 1;
    while(~scanf("%[^\n\r]", mat[n]+1)) {
        n++;
        getchar();
    }

    string s[10];

    s[0] = "**** ** ** ****";
    s[1] = "  *  *  *  *  *";
    s[2] = "***  *****  ***";
    s[3] = "***  ****  ****";
    s[4] = "* ** ****  *  *";
    s[5] = "****  ***  ****";
    s[6] = "****  **** ****";
    s[7] = "***  *  *  *  *";
    s[8] = "**** ***** ****";
    s[9] = "**** ****  ****";

    int ans = 0;
    for (int i = 1; mat[1][i]; i += 4) {
        string cur = "";
        for (int k = 1; k <= 5; k++) {
            int ok = 0;
            for (int j = i; j < i+3; j++) {
                if (mat[k][j] == '\0') ok = 1;
                if (ok) cur.pb(' ');
                else cur.pb(mat[k][j]);
            }
        }

        int num = -1;
        for (int j = 0; j < 10 && num == -1; j++) {
            if (s[j] == cur) num = j;
        }

        if (num == -1) {
            printf("BOOM!!\n");
            return 0;
        }

        ans = ans * 10 + num;        
    }

    if (ans % 6 == 0) printf("BEER!!\n");
    else printf("BOOM!!\n");

	
}