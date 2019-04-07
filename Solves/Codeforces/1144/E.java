import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class E {

	static BigInteger base26(String s) {
		int k = s.length();
		BigInteger bs = new BigInteger("0");
		
		BigInteger cur = new BigInteger("1");
		BigInteger num = new BigInteger("26");

		for (int i = k-1; i >= 0; i--) {
			Long n = (long)((int)s.charAt(i) - 97);
			bs = bs.add(cur.multiply(BigInteger.valueOf(n)));
			cur = cur.multiply(num);
		}

		return bs;
	}

	static String toBase26(BigInteger s) {
		String ans = "";

		BigInteger vs = new BigInteger("26");

		while (!s.equals(BigInteger.ZERO)) {
			ans = s.mod(vs).toString() + ans;
			s = s.divide(vs);
		}

		return ans;
	}

	public static void main(String[] args) {
		FastReader in = new FastReader();

		int k = in.nextInt();
		String s = in.nextLine();
		String t = in.nextLine();

		BigInteger bs = base26(s);
		BigInteger bt = base26(t);

		String cur = toBase26(bs.add(bt).divide(BigInteger.valueOf(2l)));

		String ans = "";
		for (int i = 0; i < cur.length(); i++) {
			int n = (int)cur.charAt(i);
			n += 97 - 48;
			ans = ans + (char)n;
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