#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e10;
const double EPS = 1e-7;
const int MAXN = 1e3 + 5;

char mat[10][10];
const int n = 8;
const int BLACK = 1;
const int WHITE = 0;

inline bool valid(int i, int j) { return i > 0 && j > 0 && i <= n && j <= n; }
inline bool pawn(char c) { return c == 'p' || c == 'P'; }
inline bool knight(char c) { return c == 'n' || c == 'N'; }
inline bool bishop(char c) { return c == 'b' || c == 'B'; }
inline bool rook(char c) { return c == 'r' || c == 'R'; }
inline bool queen(char c) { return c == 'q' || c == 'Q'; }
inline bool king(char c) { return c == 'k' || c == 'K'; }
inline bool empty(char c) { return c == '.'; };
inline int team(char c) { return c >= 'a' && c <= 'z'; }

inline bool ckPawn(int i, int j, int const T) {
	bool m1, m2;

	if (T == WHITE) {
		m1 = king(mat[i-1][j-1]) && team(mat[i-1][j-1]) == BLACK;
		m2 = king(mat[i-1][j+1]) && team(mat[i-1][j+1]) == BLACK;
	} else {
		m1 = king(mat[i+1][j-1]) && team(mat[i+1][j-1]) == WHITE;
		m2 = king(mat[i+1][j+1]) && team(mat[i+1][j+1]) == WHITE;
	}

	return m1 || m2;
}

inline bool ckKnight(int i, int j, int const T) {
	static int movk[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
	bool ret = false;

	for (int op = 0; op < 8; op++) {
		int I = i + movk[op][0], J = j + movk[op][1];
		ret |= valid(I, J) && king(mat[I][J]) && team(mat[I][J]) != T;
	}

	return ret;
}

inline bool ckBishop(int i, int j, int const T) {
	static int movb[4][2] = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

	for (int c = 0; c < 4; c++) {
		int I = i + movb[c][0], J = j + movb[c][1];
		while(valid(I, J) && empty(mat[I][J])) I += movb[c][0], J += movb[c][1];
		if (valid(I, J) && king(mat[I][J]) && team(mat[I][J]) != T) return true;
	}

	return false;
}

inline bool ckRook(int i, int j, int const T) {
	static int movr[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

	for (int c = 0; c < 4; c++) {
		int I = i + movr[c][0], J = j + movr[c][1];
		while(valid(I, J) && empty(mat[I][J])) I += movr[c][0], J += movr[c][1];
		if (valid(I, J) && king(mat[I][J]) && team(mat[I][J]) != T) return true;
	}

	return false;
}

inline bool ckQueen(int i, int j, int const T) {
	return ckBishop(i, j, T) || ckRook(i, j, T);
}

inline bool getCheck(int i, int j) {
	if (pawn(mat[i][j]))	return ckPawn(i, j, team(mat[i][j]));
	if (knight(mat[i][j]))	return ckKnight(i, j, team(mat[i][j]));
	if (bishop(mat[i][j]))	return ckBishop(i, j, team(mat[i][j]));
	if (rook(mat[i][j]))	return ckRook(i, j, team(mat[i][j]));
	if (queen(mat[i][j]))	return ckQueen(i, j, team(mat[i][j]));
	return false;
}

int main() {
	for (int cs = 1; ; cs++) {
		for (int i = 1; i <= n; i++)
			scanf(" %s", mat[i]+1);

		bool ok = false, wk = false, bk = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!empty(mat[i][j])) {
					ok = true;

					if (team(mat[i][j]) == BLACK) wk |= getCheck(i, j);
					if (team(mat[i][j]) == WHITE) bk |= getCheck(i, j);
				}
			}
		}

		if (!ok) break;
		printf("Game #%d: ", cs);
		if      (wk) printf("white king is in check.\n");
		else if (bk) printf("black king is in check.\n");
		else         printf("no king is in check.\n");
	}
}