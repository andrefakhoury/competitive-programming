/** Testing map */

import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class B {

	public static void main(String[] args) {
		FastReader in = new FastReader();

		HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();
		int n = in.nextInt();
		int m = in.nextInt();

		for (int i = 0; i < m; i++) {
			int a = in.nextInt();

			if (mp.containsKey(a)) mp.put(a, mp.get(a) + 1);
			else mp.put(a, 1);

			if (mp.size() == n) {
				for (int k = 1; k <= n; k++) {
					try {
						int qtt = mp.get(k) - 1;
						if (qtt == 0) mp.remove(k);
						else mp.put(k, qtt);
					} catch (Exception ex) {
						System.out.println(ex);
						assert(false);
					}

				}

				System.out.printf("1");
			} else System.out.printf("0");
		}

		System.out.printf("\n");
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