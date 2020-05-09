import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class C {

	public static void main(String[] args) {
		FastReader in = new FastReader();
		BigInteger factor = new BigInteger("203693490000");

		int T = in.nextInt();
		for (int cs = 1; cs <= T; cs++) {
			System.out.print("Case #" + cs + ": ");


			int n = in.nextInt();

			int d = in.nextInt();

			BigInteger[] a = new BigInteger[n];
			for (int i = 0; i < n; i++) {
				a[i] = new BigInteger(in.next());
				a[i] = a[i].multiply(factor);
			}

			long ans = 0x3f3f3f3f;

			for (int i = 0; i < n; i++) {
				BigInteger current = BigInteger.ONE;
				for (int it = 1; it <= 20; it++, current = current.add(BigInteger.ONE)) {
					BigInteger x = a[i].divide(current);

					ArrayList<Long> all = new ArrayList();
					Long currentSum = 0l;

					for (int j = 0; j < n; j++) {
						if (a[j].mod(x) == BigInteger.ZERO) {
							all.add(a[j].divide(x).longValue());
						} else {
							currentSum += a[j].divide(x).longValue();
						}
					}

					Collections.sort(all);

					long currentAns = 0;

					int D = d;
					for (Long cc : all) {
						if (D >= cc) {
							D -= cc;
							currentAns += cc-1;
						}
					}

					if (currentSum >= D) {
						currentAns += D;
						ans = Math.min(ans, currentAns);
					}
				}
			}

			System.out.println(ans);
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