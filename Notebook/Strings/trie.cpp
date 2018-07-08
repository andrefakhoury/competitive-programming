// Trie

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_NOS = 1e5 + 5;

int tn = 1; // proximo no
int term[MAX_NOS], cnt[MAX_NOS];    // zero // term = marca se a string termina ali. // cnt = quantas palavras o nó segura.
int nxt[MAX_NOS][256]; //Next nó.

string s;


void add(int at, int i) {
    cnt[at]++;
    if(i == (int)s.size()) {
        term[at]++;
        return;
    }
    
    if(nxt[at][s[i]] == -1) {
        nxt[at][s[i]] = tn;
        tn++;
    }
    
    int prox = nxt[at][s[i]];
    add(prox, i+1);
}

bool remove(int at, int i) {
    if(i == (int)s.size()) {
        cnt[at]--;
        term[at]--;
        return true;
    }
    
    if (nxt[at][s[i]] == -1)
        return 0;   
        
    int prox = nxt[at][s[i]];
    
    bool removeu = remove(prox, i+1);
    if(removeu) {
        cnt[at]--;
    }
    return removeu;
}

int count(int at, int i) {
    if(i == s.size()) {
        return term[at];
    }
    
    if(nxt[at][s[i]] == -1)
        return 0;
        
    int prox = nxt[at][s[i]];
    return count(prox, i+1);
}

int main() {
    memset(nxt, -1, sizeof nxt);

    int n;  cin >> n;
    int op;
    
    while(n--) {
        cin >> op >> s;
        if(op == 1) {
            add(0, 0);
        } if(op == 2) {
            remove(0, 0);
        } else {
            cout << count(0, 0) << endl;
        }
    }
    

    return 0;
}