import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class G {

	static BigInteger get_positive(BigInteger a, BigInteger b) {
		long lo = 0, hi = (long) 1e8, mi;
		BigInteger b1 = b.add(BigInteger.ONE);
		BigInteger TWO = BigInteger.valueOf(2l);

		BigInteger k, n;
		while(lo < hi) {
			mi = (lo + hi) / 2;

			k = b1;
			k = k.add(BigInteger.valueOf(mi).multiply(b));

			n = k;
			n = n.add(k.multiply(k));
			n = n.divide(TWO);
			n = n.subtract(k.subtract(BigInteger.ONE).multiply(a).divide(b));

			if (n.compareTo(BigInteger.ZERO) >= 0) hi = mi;
			else lo = mi + 1;
		}

		BigInteger ret = b1;
		ret = ret.add(BigInteger.valueOf(hi).multiply(b));
		return ret;
	}

	public static void main(String[] args) throws Exception {
		FastReader in = new FastReader();
		OutputStream out = new BufferedOutputStream(System.out);

		int T = in.nextInt();
		BigInteger n, k;

		ArrayList<BigInteger> num1, num2;
		BigInteger TWO = BigInteger.valueOf(2);

		while(T-- > 0) {
			BigInteger a = new BigInteger(in.next());
			BigInteger b = new BigInteger(in.next());

			num1 = new ArrayList<>();
			num2 = new ArrayList<>();
			for (k = get_positive(a, b); ; k = k.add(b)) {
				n = k;
				n = n.add(k.multiply(k));
				n = n.divide(TWO);
				n = n.subtract(k.subtract(BigInteger.ONE).multiply(a).divide(b));

				if (n.compareTo(k) > 0) break;
				num1.add(k);
				num2.add(n);
			}

			out.write((num1.size() + "\n").getBytes());
			for (int i = 0; i < num1.size(); i++)
				out.write((num1.get(i) + " " + num2.get(i) + "\n").getBytes());
		}

		out.close();
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