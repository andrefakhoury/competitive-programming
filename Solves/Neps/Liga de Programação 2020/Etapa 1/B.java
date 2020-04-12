import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class B {

	public static BigInteger TWO;
	public static BigInteger FOUR;
	public static BigInteger FIVE;

	private static boolean isSqrt(BigInteger n, BigInteger root)
	{
	    final BigInteger lowerBound = root.pow(2);
	    final BigInteger upperBound = root.add(BigInteger.ONE).pow(2);
	    return lowerBound.compareTo(n) <= 0
	        && n.compareTo(upperBound) < 0;
	}

	public static BigInteger sqrt(BigInteger n) {
		if (n.signum() >= 0) {
			final int bitLength = n.bitLength();
			BigInteger root = BigInteger.ONE.shiftLeft(bitLength / 2);
			while (!isSqrt(n, root)) root = root.add(n.divide(root)).divide(TWO);
			return root;
		}
		return BigInteger.ONE;
	}

	public static void main(String[] args) {
		TWO = new BigInteger("2");
		FOUR = new BigInteger("4");
		FIVE = new BigInteger("5");

		FastReader in = new FastReader();
		BigInteger n = new BigInteger(in.next());

		if (n.compareTo(BigInteger.ONE) == 0) {
			System.out.println("SIM");
			System.exit(0);
		}

		BigInteger x = n.multiply(n).multiply(FIVE);
		BigInteger x1 = x.add(FOUR);
		BigInteger x2 = x.subtract(FOUR);
		BigInteger xx1 = sqrt(x1);
		BigInteger xx2 = sqrt(x2);
		if (xx1.pow(2).compareTo(x1) == 0 || xx2.pow(2).compareTo(x2) == 0) {
			System.out.println("SIM");
		} else {
			System.out.println("NAO");
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