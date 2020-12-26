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

vector<string> board[25][25];

char contains(int i, int j, char c) {
    // cout << "searching for " << c << " in " << i << "," << j << endl;
    for (string& x : board[i][j]) {
        if (x[0] == c) {
            return x[1];
        } else if (x[1] == c) {
            return x[0];
        }
    }

    return -1;
}

int convert(int i, int j, int n, int m) {
    return (i - 1) * m + j;
}

char next(char c, int& x, int& y) {
    if (c == 'A') {
        x--;
        return 'F';
    } else if (c == 'B') {
        x--;
        return 'E';
    } else if (c == 'C') {
        y++;
        return 'H';
    } else if (c == 'D') {
        y++;
        return 'G';
    } else if (c == 'E') {
        x++;
        return 'B';
    } else if (c == 'F') {
        x++;
        return 'A';
    } else if (c == 'G') {
        y--;
        return 'D';
    } else if (c == 'H') {
        y--;
        return 'C';
    }

    return '0';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m;

    int T = 0;
    while(cin >> n >> m, n && m) {
        int sqr;
        while(cin >> sqr, sqr) {
            int X = (sqr - 1) / m + 1;
            int Y = (sqr - 1) % m + 1;

            // cout << sqr << ": ";
            // cout << X << ", " << Y << endl;

            string x;
            getline(cin, x);

            string t;
            for (char c : x) {
                if (c == ' ') {
                    if (t.empty()) continue;
                    board[X][Y].pb(t);
                    t.clear();
                } else {
                    t += c;
                }
            }
            if (t.size()) board[X][Y].pb(t);

            // for (string& kk : board[X][Y])
            //     cout << kk << " ";
            // cout << endl << endl;
        }
        cin.ignore();
        string allini;
        getline(cin, allini);

        // cout << allini << endl;

        vector<string> initial;
        string t;
        for (char c : allini) {
            if (c == ' ') {
                if (t.empty()) continue;
                initial.pb(t);
                t.clear();
            } else {
                t += c;
            }
        }
        if (t.size()) initial.pb(t);

        cout << "Board " << ++T << ":\n";
        for (string u : initial) {
            // cout << "\n\n\n>>>>";
            // cout << u << endl;

            cout << u << " is connected to ";
            
            char c = u.back();

            u.pop_back();
            int sqr = stoi(u);

            int X = (sqr - 1) / m + 1;
            int Y = (sqr - 1) % m + 1;

            char cc = c;

            char aa = c;
            int XX = X, YY = Y;

            // cout << XX << "," << YY << " : " << aa << endl;
            while (cc = contains(X, Y, cc), cc != -1) {
                XX = X;
                YY = Y;
                aa = cc;
                
                // cout << XX << "," << YY << " : " << aa << endl;

                cc = next(cc, X, Y);

            }

            // cout << "RESPOSTA: ";
            cout << convert(XX, YY, n, m) << aa << '\n';
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                board[i][j].clear();
            }
        }

        cout << '\n';
    }

	return 0;
}
 