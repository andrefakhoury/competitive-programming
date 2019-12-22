#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 3;

struct Event {
	int ind;
	bool type;

	Event() {}
	Event(int ind, bool type) : ind(ind), type(type) {}
};

struct Point {
	int x, y;
};

Point rects[MAXN][2];

bool cmpX(Event& a, Event& b) {
	return rects[a.ind][a.type].x < rects[b.ind][b.type].x;
}

bool cmpY(Event& a, Event& b) {
	return rects[a.ind][a.type].y < rects[b.ind][b.type].y;
}

long long unionArea(Event evV[])

int main() {

}