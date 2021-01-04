#include <bits/stdc++.h>

/** Binary Indexed Tree, aka Fenwick Tree */
template<typename T>
class BIT {
public:
	std::vector<T> bt;
	int n;

	BIT(int n) : n{n} {
		bt.resize(n + 2);
	}

	inline void update(int i, T k) {
		for (i++; i <= n + 1; i += i&-i)
			bt[i] += k;
	}

	inline T query(int i) {
		T ret{};
		for (i++; i; i -= i&-i)
			ret += bt[i];
		return ret;
	}

	inline T query(int l, int r) {
		return query(r) - query(l-1);
	}
};