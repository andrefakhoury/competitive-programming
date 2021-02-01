/** Binary Indexed Tree, aka Fenwick Tree */
template<typename T> struct BIT {
	std::vector<T> bt;
	int n;

	BIT(int n) : n{n} {
		bt.resize(n + 2);
	}

	inline void init(int sz) {
		n = sz;
		bt.assign(n + 2, 0);
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
		if (l > r) return 0;
		return query(r) - query(l-1);
	}
};
