import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class A {

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

	static void impossible() {
		System.out.println("-1");
		System.exit(0);
	}

	public static void main(String[] args) {
		FastReader in = new FastReader();

		String s = in.nextLine();

		int cl = -1, op = 0;
		for (int i = s.length()-1; i > 0; i--) {
			if (op == 0 && s.charAt(i) == ']') op++;
			if (op == 1 && s.charAt(i) == ':') cl = i;
			if (cl != -1) break;
		}

		if (cl == -1) impossible();

		op = 0;
		int ans = 0;
		for (int i = 0; i < cl; i++) {
			if (op == 0 && s.charAt(i) == '[') op++;
			if (op == 1 && s.charAt(i) == ':') op++;
			if (op == 2 && s.charAt(i) == '|') ans++;
		}

		if (op != 2) impossible();
		System.out.println(ans + 4);
	}
}