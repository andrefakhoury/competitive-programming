/** Wavelet Tree data structure. Input array is 0 based */
struct waveletTree {
	int lo, hi, mi; // minimum, maximum and (lo+hi)/2 element on array
	waveletTree *L, *R; // children
	vector<int> mp; // map how many elements went left

#define ML(i) (mp[i]) /* original mapLeft */
#define MR(i) (i - mp[i] - 1) /* original mapRight */

	/** *beg points to the first element, *end points to after the last element (just like stl default functions)
	  * Array values are between range [lo..hi] */
	waveletTree(int *beg, int *end, int lo, int hi) { // O(nlogA)
		L = R = NULL;
		this->lo = lo;
		this->hi = hi;
		this->mi = (lo + hi) / 2;
		if (beg >= end) return; // no elements to insert

		mp.reserve(end - beg + 1);
		mp.push_back(0);
		for (auto it = beg; it != end; it++)
			mp.push_back(mp.back() + ((*it) <= mi));
		if (lo != hi) {
			auto pivot = stable_partition(beg, end, f); // split the vector
			L = new waveletTree(beg, pivot, lo, mi);
			R = new waveletTree(pivot, end, mi + 1, hi);
		}
	}

	/** Frequency of k on range [1..i] */
	int rank(int k, int i) {
		if (lo == hi) return k == lo ? i : 0; // leaf node - just one value available
		else { // keep searching
			if (k <= mi) return L->rank(k, ML(i));
			else return R->rank(k, MR(i));
		}
	}

	/** Frequency of k in range [i..j] */
	int rank(int k, int i, int j) {
		return rank(k, j) - rank(k, i - 1); // similar to prefix sum
	}

	/** K-th smallest element on range[l..r] */
	int kthSmallest(int k, int l, int r) {
		if (l > r) return -1; // out of bounds
		if (lo == hi) return lo; // leaf node

		int inLeft = ML(r) - ML(l-1);
		if (k <= inLeft) return L->kthSmallest(k, ML(l-1)+1, ML(r));
		else return R->kthSmallest(k-inLeft, MR(l-1)+1, MR(r));
	}

	/** Qtt of elements between [x..y] in array[l..r] */
	int rangeCount(int x, int y, int l, int r) {
		if (l > r || lo > y || hi < x) return 0; // out of bounds
		if (lo >= x && hi <= y) return r - l + 1; // total fit
		return L->rangeCount(x, mi, ML(l-1)+1, ML(r)) +  // same idea of segtree
			   R->rangeCount(mi+1, y, MR(l-1)+1, MR(r));
	}

	/** Find minimum X such that freq[x] on interval l..r is strictly greater thank k */
	int findFreqGreater(int k, int l, int r) {
		if (r - l + 1 <= k) return -1;
		if (lo == hi) return lo;
		int cur = L->findFreqGreater(k, ML(l-1)+1, ML(r));
		if (cur != -1) return cur;
		return R->findFreqGreater(k, MR(l-1)+1, MR(r));
	}

	/** Swap elements a[i] and a[i+1] */
	void swapContiguous(int i) {
		if (lo == hi) return; // leaf node, no need to swap

		bool iLeft = ML(i) == ML(i-1) + 1; // if a[i] <= mi
		bool i1Left = (ML(i+1)) == (ML(i) + 1); // if a[i+1] <= mi

		if (iLeft && !i1Left) ML(i)--;
		else if (iLeft && i1Left) L->swapContiguous(ML(i));
		else if (!iLeft && i1Left) ML(i)++;
		else R->swapContiguous(MR(i));
	}

	/** Push element k to end of array */
	void push_back(int k) {
		mp.push_back(mp.back() + (k <= mi));
		if (lo != hi) {
			if (k <= mi) L->push_back(k);
			else R->push_back(k);
		}
	}

	/** Pop element k from the end of array */
	void pop_back(int k) {
		mp.pop_back();
		if (lo != hi) {
			if (k <= mi) L->pop_back(k);
			else R->pop_back(k);
		}
	}

	~waveletTree() {
		if (L) delete L;
		if (R) delete R;
	}
};
