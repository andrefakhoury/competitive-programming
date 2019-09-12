#include <bits/stdc++.h>
using namespace std;

template<typename T>
class minStack {
	stack<pair<T, T> > st;

	public:
	minStack() {}
	void add(T elem) {
		T nmin = st.empty() ? elem : min(elem, st.top().second);
		st.push(make_pair(elem, nmin));
	}

	void remove() {
		if (st.size())
			st.pop();
	}

	T minimum() {
		return st.top().second;
	}
};

template<typename T>
class minQueue {
	stack<pair<T, T> > s1, s2;

	public:
	T minimum() {
		if (s1.empty() || s2.empty())
			return s1.empty() ? s2.top().second : s1.top().second;
		else
			return min(s1.top().second, s2.top().second);
	}

	void add(T elem) {
		T minimum = s1.empty() ? elem : min(elem, s1.top().second);
		s1.push(make_pair(elem, minimum));
	}

	T remove() {
		while(s1.size()) {
			T elem = s1.top().first;
			s1.pop();
			T minimum = s2.empty() ? elem : min(elem, s2.top().second);
			s2.push(make_pair(elem, minimum));
		}
		T remove_element = s2.top().first;
		s2.pop();
		return remove_element;
	}
};

template<typename T>
class minQueue_1 {
	deque<T> q;

	public:
	T minimum() {
		return q.front();
	}

	void add(T elem) {
		while(!q.empty() && q.back() > elem)
			q.pop_front();
		q.push_back(elem);
	}

	void remove(T elem) {
		if (!q.empty() && q.front() == elem)
			q.pop_front();
	}
};

template<typename T>
class minQueue_2 {
	deque<pair<T, T> > q;
	int cnt_added, cnt_removed;

	public:
	minQueue_2() {
		cnt_added = cnt_removed = 0;
	}

	T minimum() {
		return q.front().first;
	}

	void add(T elem) {
		while(!q.empty() && q.back().first > elem)
			q.pop_back();
		q.push_back(make_pair(elem, cnt_added));
		cnt_added++;
	}

	void remove(T elem) {
		if (!q.empty() && q.front().second == cnt_removed)
			q.pop_front();
		cnt_removed++;
	}
};

int main() {
	// Given an array A of length N and M≤N.
	// Find the minimum of each subarray of length M in this array

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	minQueue_1<int> mq;

	int m; cin >> m;
	for (int i = 0; i < m; i++) mq.add(a[i]);
	cout << mq.minimum() << endl;

	for (int i = m; i < n; i++) {
		mq.add(a[i]);
		mq.remove(a[i-m]);
		cout << mq.minimum() << endl;
	}
}