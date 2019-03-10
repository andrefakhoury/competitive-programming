import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class B {

	public static void main(String[] args) {
		FastReader in = new FastReader();

		Integer n = in.nextInt();
		Integer m = in.nextInt();
		Integer k = in.nextInt();

		Integer []a = new Integer[n];

		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();

		Integer ind[] = new Integer[k];
		Long total = 0l;
		Long cur = 0l;

		Integer ign = n - m*k;

		//tenho que deixar os ign menores de fora, ou seja, em algum grupo com +m elementos

		for (int i = 0; i < n; i++) {

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