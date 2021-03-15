import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class I {

    public static class carinha {
        String name;
        BigInteger bet;

        public carinha(String x, String y) {
            name = x;
            bet = new BigInteger(y);
        }
    }

    static class BetComparator implements Comparator<carinha> {

        @Override
        public int compare(carinha o1, carinha o2) {
            return - o1.bet.compareTo(o2.bet);
        }
    }

    public static void solve() {
        FastReader in = new FastReader();

        int n = in.nextInt();
        BigInteger x = new BigInteger(in.next());

        List<carinha> vec = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            vec.add(new carinha(in.next(), in.next()));
        }

        Collections.sort(vec, new BetComparator());
        
        List<String> ans = new ArrayList<>();

        for (carinha ac : vec) {
            if (ac.bet.compareTo(x) <= 0) {
                x = x.subtract(ac.bet);
                ans.add(ac.name);
            }
        }

        if (x.compareTo(BigInteger.ZERO) != 0) ans.clear();

        System.out.println(ans.size());
        for (String xx : ans) {
            System.out.println(xx);
        }
    }

	public static void main(String[] args) {
        solve();
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