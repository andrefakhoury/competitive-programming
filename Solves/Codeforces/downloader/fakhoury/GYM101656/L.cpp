#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define ll long long
 typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 char prev_vogal(char a) {
    static char const letr[] = "aiyeou";
    int i = find(letr, end(letr), a) - letr;
     i = (i + 6 -3) % 6; 
    return letr[i];
}
 char prev_con(char a) {
    static char const letr[] = "bkxznhdcwgpvjqtsrlmf";
    int i = find(letr, end(letr), a) - letr;
     i = (i + 20 -10) % 20;
    return letr[i];
}
 int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
     string s;
    while (getline(cin, s)) {
        for (char a : s) {
            bool tp = false;
           if (isupper(a)) {
                tp = true;
                a = tolower(a); 
           }
           static char const vog[] = "aiyeou";
            static char const cons[] = "bkxznhdcwgpvjqtsrlmf";
             if (find(begin(vog), end(vog), a) != end(vog)) {
                a = prev_vogal(a);
            }
            else if (find(begin(cons), end(cons), a) != end(cons)) {
                a = prev_con(a);
            }
             if (tp) a = toupper(a);
            cout << a;
        }
        cout << "\n";
    }
     return 0;
}