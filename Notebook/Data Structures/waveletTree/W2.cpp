#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
#define vi vector<int>
#define pb push_back
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================
vi g[N];
int a[N];
struct wavelet_tree{
	int lo, hi;
	wavelet_tree *l, *r;
	vi b;
 
	//nos are in range [x,y]
	//array indices are [from, to)
	wavelet_tree(int *from, int *to, int x, int y){
		l = r = NULL;

		lo = x, hi = y;
		if( from >= to) return;
		if( hi == lo ){
			b.reserve(to-from+1);
            		b.pb(0);
            		for(auto it = from; it != to; it++){
            			b.pb(b.back() + 1);
            		}
			return;
		}
		int mid = (lo+hi)/2;
		if (hi == mid) mid = lo;

		auto f = [mid](int x){
			return x <= mid;
		};
		b.reserve(to-from+1);
		b.pb(0);
		for(auto it = from; it != to; it++){
			b.pb(b.back() + f(*it));
		}
		//see how lambda function is used here	
		auto pivot = stable_partition(from, to, f);
		l = new wavelet_tree(from, pivot, lo, mid);
		r = new wavelet_tree(pivot, to, mid+1, hi);
	}
 
	//kth smallest element in [l, r]
	int kth(int l, int r, int k){
		if(l > r) return -1;
		if(lo == hi) return lo;
		int inLeft = b[r] - b[l-1];
		int lb = b[l-1]; //amt of nos in first (l-1) nos that go in left 
		int rb = b[r]; //amt of nos in first (r) nos that go in left
		if(k <= inLeft) return this->l->kth(lb+1, rb , k);
		return this->r->kth(l-lb, r-rb, k-inLeft);
	}
 
	~wavelet_tree(){
		if (l) delete l;
		if (r) delete r;
	}
};
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int i, n, q; cin >> n >> q;
	fo(i, n) cin >> a[i+1];
	wavelet_tree T(a+1, a+n+1, -1e9, 1e9);


	while(q--){
		int l, r, k; cin >> l >> r >> k;
		cout << T.kth(l, r, k) << '\n';
	}
	return 0;
} 