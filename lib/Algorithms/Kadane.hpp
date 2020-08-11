#include <bits/stdc++.h>

template <typename T=long long, typename M>
T kadane(std::vector<M> const& v) {
	T ret{}, cur = std::numeric_limits<M>::min();
	for (auto x : v) {
		cur = std::max(cur + x, static_cast<T>(x));
		ret = std::max(ret, cur);
	}
	return ret;
}