/** Testing java execution time and arrays */

import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class B {

	static int sum[][] = new int[1000001][10];
	static int fmemo[] = new int[1000001];
	static int gmemo[] = new int[1000001];

	static int f(int x) {
		if (fmemo[x] != 0) return fmemo[x];
		int n = x;

		int ret = 1;
		while(x > 0) {
			if (x % 10 != 0) ret *= x%10;
			x /= 10;
		}

		return fmemo[n] = ret;
	}

	static int g(int x) {
		if (gmemo[x] != 0) return gmemo[x];

		if (x < 10) return gmemo[x] = x;
		return gmemo[x] = g(f(x));
	}

	static void pre() {
		for (int n = 1; n <= 1000000; n++) {
			g(n);
		}

		for (int k = 1; k <= 9; k++) {
			for (int n = 1; n <= 1000000; n++) {
				sum[n][k] = sum[n-1][k];
				if (gmemo[n] == k) sum[n][k]++;
			}
		}
	}

	static int solve(int l, int r, int k) {
		return sum[r][k] - sum[l-1][k];
	}

	public static void main(String[] args) {
		FastReader in = new FastReader();
		pre();

		int q = in.nextInt();

		while(q--> 0) {
			int l = in.nextInt();
			int r = in.nextInt();
			int k = in.nextInt();
			System.out.println(solve(l, r, k));
		}
	}

	/** Reader class */
	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}