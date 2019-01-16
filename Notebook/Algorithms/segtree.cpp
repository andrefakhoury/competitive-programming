int v[MAXN], st[4*MAXN];
void build(int node, int l, int r) { //O(N)
	if (l == r) st[node] = v[l]; //leaf
	else {
		build(2*node, l, (l+r)/2);
		build(2*node+1, (l+r)/2+1, r);
		st[node] = st[2*node] + st[2*node+1];
	}
}

void update(int node, int l, int r, int id, int x) { //O(logN)
	//v[id] = x
	
	if (l == r) { //found the leaf
		v[l] = x;
		st[node] = x;
	} else { //update the rest
		int mid = (l+r)/2;
		if (l <= id && id <= mid) update(2*node, l, mid, id, x);
		else update(2*node+1, mid+1, r, id, x);
		st[node] = st[2*node] + st[2*node+1];
	}
}

int query(int node, int l, int r, int a, int b) { //O(logN)
	if (l > b || r < a) return 0; //out of bounds

	if (l >= a && r <= b) return st[node]; //all in interval
	
	int mid = (l+r)/2;
	return query(2*node, l, mid, a, b) + query(2*node+1, mid+1, r, a, b);
}

//LAZY PROPAGATION
