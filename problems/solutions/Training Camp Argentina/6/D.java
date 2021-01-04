import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class D {

	public static void main(String[] args) {
		FastReader in = new FastReader();

		BigInteger a = new BigInteger(in.next());
		int b = in.nextInt();
		BigInteger r = a.pow(b);

		long last = 0;
		String rr = r.toString();
		for (int i = 0; i < rr.length(); i++)
			last += rr.charAt(i) - '0';

		while(true) {
			long curr = 0;
			long ll = last;
			while(ll > 0) {
				curr += ll % 10;
				ll /= 10;
			}
			if (curr == last) break;
			last = curr;
		}

		System.out.println(last);
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