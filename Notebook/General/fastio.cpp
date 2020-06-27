#include <bits/stdc++.h>
using namespace std;

namespace FastIO {
	template<class num> inline void rd_int(num &x) {
		char c; bool neg = false;
		while(isspace(c = getchar_unlocked()));
		if(!isdigit(c)) neg = (c == '-'), x = 0;
		else x = c - '0';
		while(isdigit(c = getchar_unlocked()))
			x = (x << 3) + (x << 1) + c - '0';
		if (neg) x = -x;
	}

	template<class T, class... Args> inline void rd_int(T& x, Args&... args) {
		rd_int(x); rd_int(args...);
	}

	inline void print_int(int&& x) { // TODO
		printf("%d", x);
	}
};

int main() {
	
}