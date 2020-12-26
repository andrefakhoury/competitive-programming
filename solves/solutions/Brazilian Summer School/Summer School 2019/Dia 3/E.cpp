#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b)	 for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define endl "\n"
#define MAX 200
#define WHITE 1
#define BLACK 0
bool wcheck = false;
bool bcheck = false;
string mat[10];

int n=8,m=8;

void pawn(int cor,int i,int j)
{
	if(cor == BLACK)
	{
		if(i+1<n)
		{
			if(j+1<m)
				if(mat[i+1][j+1]=='K')
					wcheck = true;
			if(j-1<m)
				if(mat[i+1][j-1] == 'K')
					wcheck = true;
		}
	}
	if(cor == WHITE)
	{
		if(i-1>=0)
		{
			if(j+1<m)
				if(mat[i-1][j+1]=='k')
					bcheck = true;
			if(j-1<m)
				if(mat[i-1][j-1] =='k')
					bcheck = true;
		}
	}
}
void rook(int cor,int i,int j)
{
	int auxi = i;
	int auxj = j;
	i--;
	while(i>=0)
	{
		if(mat[i][j]!='.')
		{
			

			if(cor == BLACK)
			{
				if(mat[i][j] == 'K')
					wcheck = true;
			}
			if(cor == WHITE)
			{
				if(mat[i][j] == 'k')
					bcheck = true;
			}
			break;
		}
		i--;
	}
	i = auxi;
	i++;
	while(i<n)
	{
		if(mat[i][j]!='.')
		{
			if(mat[i][j]!='K' and mat[i][j] != 'k')
				break;

			if(cor == BLACK)
			{
				if(mat[i][j] == 'K')
					wcheck = true;
			}
			if(cor == WHITE)
			{
				if(mat[i][j] == 'k')
					bcheck = true;
			}
			break;
		}
		i++;
	}
	i = auxi;
	j = auxj;
	j--;
	while(j>=0)
	{
		if(mat[i][j]!='.')
		{
			if(mat[i][j]!='K' and mat[i][j] != 'k')
				break;

			if(cor == BLACK)
			{
				if(mat[i][j] == 'K')
					wcheck = true;
			}
			if(cor == WHITE)
			{
				if(mat[i][j] == 'k')
					bcheck = true;
			}
			break;
		}
		j--;
	}
	j = auxj;
	j++;
	while(j<n)
	{
		if(mat[i][j]!='.')
		{
			if(mat[i][j]!='K' and mat[i][j] != 'k')
				break;

			if(cor == BLACK)
			{
				if(mat[i][j] == 'K')
					wcheck = true;
			}
			if(cor == WHITE)
			{
				if(mat[i][j] == 'k')
					bcheck = true;
			}
			break;
		}
		j++;
	}
}


void bishop(int cor,int i,int j)
{
	int auxi =i;
	int auxj=j;
	i--;
	j--;
	while(i>=0 and j>=0)
	{
		if(mat[i][j]!='.')
		{
			if(mat[i][j]!='K' and mat[i][j] != 'k')
				break;

			if(cor == BLACK)
			{
				if(mat[i][j] == 'K')
					wcheck = true;
			}
			if(cor == WHITE)
			{
				if(mat[i][j] == 'k')
					bcheck = true;
			}
			break;
		}
		i--;
		j--;
	}
	i = auxi;
	j = auxj;
	i--;
	j++;
	while(i>=0 and j<n)
	{
		if(mat[i][j]!='.')
		{
			if(mat[i][j]!='K' and mat[i][j] != 'k')
				break;

			if(cor == BLACK)
			{
				if(mat[i][j] == 'K')
					wcheck = true;
			}
			if(cor == WHITE)
			{
				if(mat[i][j] == 'k')
					bcheck = true;
			}
			break;
		}
		i--;
		j++;
	}
	i = auxi;
	j = auxj;
	i++;
	j++;
	while(i<n and j<n)
	{
		if(mat[i][j]!='.')
		{
			if(mat[i][j]!='K' and mat[i][j] != 'k')
				break;

			if(cor == BLACK)
			{
				if(mat[i][j] == 'K')
					wcheck = true;
			}
			if(cor == WHITE)
			{
				if(mat[i][j] == 'k')
					bcheck = true;
			}
			break;
		}
		i++;
		j++;
	}
	i = auxi;
	j = auxj;
	i++;
	j--;
	while(i<n and j>=0)
	{
		if(mat[i][j]!='.')
		{
			if(mat[i][j]!='K' and mat[i][j] != 'k')
				break;

			if(cor == BLACK)
			{
				if(mat[i][j] == 'K')
					wcheck = true;
			}
			if(cor == WHITE)
			{
				if(mat[i][j] == 'k')
					bcheck = true;
			}
			break;
		}
		i++;
		j--;
	}
}
void knight(int cor,int i,int j)
{
	if(i+2<n)
	{
		if(j+1<n)
		{
			if(mat[i+2][j+1] == 'k' and cor == WHITE)
				bcheck = true;
			if(mat[i+2][j+1] == 'K' and cor == BLACK)
				wcheck = true;
		}
		if(j-1>=0)
		{
			if(mat[i+2][j-1] == 'k' and cor == WHITE)
				bcheck = true;
			if(mat[i+2][j-1] == 'K' and cor == BLACK)
				wcheck = true;
		}
	}
	if(i-2>=0)
	{
		if(j+1<n)
		{
			if(mat[i-2][j+1] == 'k' and cor == WHITE)
				bcheck = true;
			if(mat[i-2][j+1] == 'K' and cor == BLACK)
				wcheck = true;
		}
		if(j-1>=0)
		{
			if(mat[i-2][j-1] == 'k' and cor == WHITE)
				bcheck = true;
			if(mat[i-2][j-1] == 'K' and cor == BLACK)
				wcheck = true;
		}
	}
	if(j+2<n)
	{
		if(i+1<n)
		{
			if(mat[i+1][j+2]== 'k' and cor == WHITE)
				bcheck = true;
			if(mat[i+1][j+2]== 'K' and cor == BLACK)
				wcheck = true;
		}
		if(i-1>=0)
		{
			if(mat[i-1][j+2]== 'k' and cor == WHITE)
				bcheck = true;
			if(mat[i-1][j+2]== 'K' and cor == BLACK)
				wcheck = true;
		}
	}
	if(j-2>=0)
	{
		if(i+1<n)
		{
			if(mat[i+1][j-2]== 'k' and cor == WHITE)
				bcheck = true;
			if(mat[i+1][j-2]== 'K' and cor == BLACK)
				wcheck = true;
		}
		if(i-1>=0)
		{
			if(mat[i-1][j-2]== 'k' and cor == WHITE)
				bcheck = true;
			if(mat[i-1][j-2]== 'K' and cor == BLACK)
				wcheck = true;
		}
	}
}

int main()
{	
	fastcin;
	int casos = 0;
	while(1)
	{
		bcheck = false;
		wcheck = false;
		bool para = true;
		for(int i=0;i<n;i++)
		{
			cin >> mat[i];
			for(int j = 0;j<n;j++)
			{
				if(mat[i][j]!='.')
					para = false;
			}
		}
		if(para)
			break;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(mat[i][j] == 'P')// white
					pawn(WHITE,i,j);

				if(mat[i][j] == 'R')
					rook(WHITE,i,j);

				if(mat[i][j] == 'B')	
					bishop(WHITE,i,j);

				if(mat[i][j] == 'Q')
				{	
					bishop(WHITE,i,j);
					rook(WHITE,i,j);
				}

				if(mat[i][j] == 'N')
					knight(WHITE,i,j);


				if(mat[i][j] == 'p')// black
					pawn(BLACK,i,j);

				if(mat[i][j] == 'r')
					rook(BLACK,i,j);

				if(mat[i][j] == 'q')
				{
					bishop(BLACK,i,j);
					rook(BLACK,i,j);
				}
				if(mat[i][j] == 'b')
					bishop(BLACK,i,j);


				if(mat[i][j] == 'n')
					knight(BLACK,i,j);
			}
		}
		casos++;
		if(bcheck == true)
			cout << "Game #" << casos << ": black king is in check." << endl;
		else if(wcheck == true)
			cout << "Game #" << casos << ": white king is in check." << endl;
		else
			cout << "Game #" << casos << ": no king is in check." << endl;
	}
}
