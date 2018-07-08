#include <bits/stdc++.h>

using namespace std;

#define pb push_back

struct dev {
	int power, begin;
	dev() {}
	dev(int x, int y) {
		this->power = x; this->begin = y;
	}
};

vector<dev> vec;

int main() {
	int n, p, x, y; scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y); vec.pb(dev(x, y));
	}
	

}