int n, vec[MAXN];

int binsearch(int x) {
	int begin=1, end=n, mid;

	while(begin<=end){
		mid=(begin+end)/2;

		if(vec[mid] == x) return mid;
		if(vec[mid] < x)  begin = mid+1;
		if(vec[mid] > x)  end = mid-1;
	}

	return -1; // x !in vec
}