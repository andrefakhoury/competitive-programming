/*
	Given an array P of size N and an Integer S,
	find 4 numbers (a, b, c, d) such that:
	a + b + c + d = S, {a, b, c, d} in P

	Example:
	
	input
	4 10
	1 2 3 4

	output
	1 2 3 4
*/

/**
	There's a problem with this approach. Using the meet in the middle method,
	the elements can actually be repeated 2 times, and we don't want that.

	How you can solve it? I don't know heheh
*/

import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Example1 {

	public static void main(String[] args) {
		FastReader in = new FastReader();

		int n = in.nextInt();
		int s = in.nextInt();
		int p[] = new int[n];

		for (int i = 0; i < n; i++)
			p[i] = in.nextInt();

		System.out.println("Naive method:");
		naiveMethod(n, s, p);

		System.out.println("\nMeet in the Middle:");
		solve(n, s, p);		
	}

	/** O(n^4) brute force, just try every number */
	private static void naiveMethod(int n, int s, int p[]) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					for (int l = k + 1; l < n; l++) {
						if (p[i] + p[j] + p[k] + p[l] == s) {
							System.out.printf("%d %d %d %d\n", p[i], p[j], p[k], p[l]);
							return;
						}
					}
				}
			}
		}
		
		System.out.println("No solution found...");
	}

	private static void solve(int n, int s, int p[]) {
		/** We can simplify the problem in that way:
			
			a + b + c + d = S
			
			a + b = x
			c + d = y
			
			x + y = s
			x = s - y

			So, we can just brute {X} and {S - y} in O(n^2), and then find the occurences of {X} in {S - y}
			Lets call {S - y} Y
		*/

		HashMap<Integer, Pair> X = new HashMap<Integer, Pair>();
		HashMap<Integer, Pair> Y = new HashMap<Integer, Pair>();

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				X.put(p[i] + p[j], new Pair(p[i], p[j]));
				Y.put(s - (p[i] + p[j]), new Pair(p[i], p[j]));
			}
		}

		/** Search for a occurence of X in Y */
		for (HashMap.Entry<Integer, Pair> x : X.entrySet()) {
			Object y = Y.get(x.getKey());
			if (y != null) {
				System.out.println(x.getValue() + " " + y);
				return;
			}			
		}

		System.out.println("No solution found...");
	}

	/** pair of {int, int} */
	static class Pair {
		int x, y;
		Pair(int a, int b) {
			x = a;
			y = b;
		}

		public String toString() {
			return x + " " + y;
		}
	}

	/** Reader class, just ignore **/
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