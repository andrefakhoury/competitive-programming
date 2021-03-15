#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define fi first
#define se second;
#define rank jdksl

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int N = 100007, inf = 0x3f3f3f3f;

void legend() {
	cout << "Legend" << endl;
	exit(0);
}

int tot[50];

int rank = 25;
int cur = 0, stars = 0;

void inc() {
	stars++;
	if(stars > tot[rank]) {
		stars = 1;
		rank--;
		if(rank == 0) legend();
	}
}

void dec() {
	if(rank >= 1 and rank <= 20) stars--;
	if(stars < 0) {
		if(rank == 20) {
			stars = 0;
		} else {
			rank++;
			stars = tot[rank]-1;
		}
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    tot[25] = tot[24] = tot[23] = tot[22] = tot[21] = 2;
    tot[20] = tot[19] = tot[18] = tot[17] = tot[16] = 3;
    tot[15] = tot[14] = tot[13] = tot[12] = tot[11] = 4;
    tot[10] = tot[9] = tot[8] = tot[7] = tot[6] = tot[5] = tot[4] = tot[3] = tot[2] = tot[1] = 5;
    string s; cin >> s;

    
    for(char c : s) {
    	if(c == 'W') {
    		cur++;
    		if(cur >= 3 and rank >= 6) inc();
    		inc();

    	} else {
    		dec();
    		cur = 0;

    	}
    }

    cout << rank << endl;

}