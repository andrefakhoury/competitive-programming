import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class J {
	String s, t;
	int ind = 0;

	static boolean check(int k) {
		return true;
	}

	public static void main(String[] args) {
		FastReader in = new FastReader();

		s = in.nextLine();
		t = in.nextLine();

		int lo = 0, hi = t.length() + 1, mi;
		int qtt = 0;

		while (lo <= hi) {
			mi = (lo+hi)/2;
			if (check(mi)) {
				qtt = mi;
				lo = mi + 1LL;
			}

			else hi = mi - 1;
		}

		if (qtt == 0) {
			System.out.println("0");
		} else {
			for (int i = ind; i < ind + qtt; i++) {
				System.out.printf("%c", t.charAt(i));
			}
			System.out.printf("\n%d\n", qtt);
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