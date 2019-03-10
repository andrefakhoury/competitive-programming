import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class A {
	static void impossible() {
		System.out.println("NO");
		System.exit(0);
	}

	public static void main(String[] args) {
		FastReader in = new FastReader();

		Integer x = in.nextInt();
		Integer y = in.nextInt();
		Integer z = in.nextInt();
		Integer a = in.nextInt();
		Integer b = in.nextInt();
		Integer c = in.nextInt();

		Integer used = 0;
		if (a < x) impossible();
		used += x;

		if (a + b - used < y) impossible();
		used += y;

		if (a + b + c - used < z) impossible();
		System.out.println("YES");

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