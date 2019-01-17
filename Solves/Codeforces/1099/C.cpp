#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 100000, INF = 0x3f3f3f3f;

string enc;
int k;

void impossible() {
	cout << "Impossible\n";
	exit(0);
}

bool ehLetra(char c) {
	return (c >= "a" && c <= "z") or (c >= "A" && c <= "Z") or (c == "0");
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> enc >> k;
	int sn = 0, cn = 0;

	for (int i = 0; i < (int)enc.size(); i++) {
		if (enc[i] == "*") sn++;
		if (enc[i] == "?") cn++;
	}

	int l = (int)enc.size() - sn - cn;

	if (l - sn - cn > k) impossible();
	if (l < k && sn == 0) impossible();

	string ans;

	int saldo = k - l - sn - cn;

	enc += "00000";

	int num = 0;
	for (int i = 0; i < (int)enc.size()-5; i++) {
		if (ehLetra(enc[i]) && ehLetra(enc[i+1])) num++;
	}

	// cout << num << endl;
	saldo = k - num;

	for (int i = 0; i < (int)enc.size()-5; i++) {
		// printf("i: %d; saldo: %d\n", i, saldo);

		if (ehLetra(enc[i]) && ehLetra(enc[i+1])) {
			ans.pb(enc[i]);
		} else if (ehLetra(enc[i]) && enc[i+1] == "?") {
			if (saldo > 0) {
				ans.pb(enc[i]);
				saldo--;
				i++;
			} else if (saldo < 0) {
				i++;
				saldo++;
			}
		} else if (ehLetra(enc[i]) && enc[i+1] == "*") {
			if (saldo > 0) {
				for (int j = 0; j < saldo; j++) {
					ans.pb(enc[i]);
				}
				saldo = 0;
				i++;
			} else if (saldo < 0) {
				i++;
				saldo++;
			}
		}
	}


	cout << ans << endl;

	return 0;
}