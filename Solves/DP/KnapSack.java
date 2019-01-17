import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class KnapSack {
	private static int n, w;
	private static Product[] a;

	private static long[][] memo;

	public static void main(String[] args) {
		FastReader in = new FastReader();

		n = in.nextInt();
		w = in.nextInt();

		memo = new long[n+1][w+1];
		a = new Product[n];

		for (int i = 0; i < n; i++) {
			long _p = in.nextLong();
			int _w = in.nextInt();

			a[i] = new Product(_p, _w);
		}

		System.out.println(solve(0, 0, 0));
	}

	//O(N*W) solution
	static long solve(int at, int weight, long val) {
		if (at >= n) return weight <= w ? val : -1;
		if (weight > w) return -1;

		if (memo[at][weight] != 0) return memo[at][weight];

		return memo[at][weight] = Math.max(solve(at+1, weight + a[at].weight, val + a[at].price), solve(at+1, weight, val));
	}

	static class Product {
		long price;
		int weight;
		
		Product(long p, int w) {
			price = p;
			weight = w;
		}

		public String toString() {
			return "Price: " + price + "; Weight: " + weight;
		}
	}

	/** Reader class, just ignore **/
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