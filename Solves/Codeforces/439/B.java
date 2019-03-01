import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class B {

	public static void main(String[] args) {
		FastReader in = new FastReader();

		Integer n = in.nextInt();
		Long x = in.nextLong();

		Long []c = new Long[n];
		for (int i = 0; i < n; i++) c[i] = in.nextLong();

		Arrays.sort(c);

		Long ans = 0l;
		for (int i = 0; i < n; i++) {
			ans += c[i] * x;
			x = Math.max(x - 1, 1);
		}

		System.out.println(ans);
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