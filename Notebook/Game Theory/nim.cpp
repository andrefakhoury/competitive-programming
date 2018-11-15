const int MAXN = 100005;
int piles[MAXN];

int nimSum(int n) { //returns the grungy number
	int num = 0;
	for (int i = 0; i < n; i++) num ^= piles[i];
	return num;
}

int predict(int n) {
	if (nimSum(n) != 0) return 1; 	//player 1
	else return 2;					//player 2
}