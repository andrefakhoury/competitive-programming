import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class B {

	static double getSum(int l, int r, long []sum) {
		return sum[r] - sum[l];
	}

	public static void main(String[] args) {
		FastReader in = new FastReader();
		Integer n = in.nextInt();
		Integer k = in.nextInt();
		Integer m = in.nextInt();
		Integer []a = new Integer[n];


		for (int i = 0; i < n; i++) a[i] = in.nextInt();
		Arrays.sort(a);

		long []sum = new long[n];
		sum[0] = a[0];
		for (int i = 1; i < n; i++) sum[i] = sum[i-1] + a[i];

		double ans = getSum(0, n-1, sum) / n;

		for (int i = 0; i < n; i++) {
			int qtt = Math.min((n - i + 1)*k, m - i + 1);
			double cur = (getSum(i, n-1, sum) + qtt) / (n - i + 1);
			ans = Math.max(ans, cur);
		}

		System.out.printf("%.9lf\n", ans);		
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