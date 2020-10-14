#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct CoordCompression {
	vector<T> allValues;

	CoordCompression(vector<T> const& original) {
		this->allValues = original;
		sort(allValues.begin(), allValues.end());
		allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end());
	}

	inline bool hasValue(T val) {
		return binary_search(allValues.begin(), allValues.end(), val);
	}

	inline int getCompressed(T val) {
		return lower_bound(allValues.begin(), allValues.end(), val) - allValues.begin();
	}

	inline T& operator[](size_t position) {
		return allValues[position];
	}

	inline T& at(size_t position) {
		return allValues[position];
	}
};