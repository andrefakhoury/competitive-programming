import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author fakhoury
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BPalindromicPaths solver = new BPalindromicPaths();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class BPalindromicPaths {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            int[] a = new int[n * m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i * m + j] = in.nextInt();
                }
            }

            int[] par = new int[n * m];
            int[] siz = new int[n * m];
            for (int i = 0; i < n * m; i++) {
                par[i] = i;
                siz[i] = 1;
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int ni = i; ni < n; ni++) {
                        for (int nj = j; nj < m; nj++) {
                            if (i + j == n - ni - 1 + m - nj - 1) {
                                merge(i * m + j, ni * m + nj, par, siz);
                            }
                        }
                    }
                }
            }

            int[][] count = new int[2][n * m];
            for (int pos = 0; pos < n * m; pos++) {
                count[a[pos]][find(pos, par)]++;
            }

            int answer = 0;
            for (int i = 0; i < n * m; i++) {
                answer += Math.min(count[0][i], count[1][i]);
            }

            out.println(answer);
        }

        int find(int x, int par[]) {
            if (par[x] == x) {
                return x;
            } else {
                return par[x] = find(par[x], par);
            }
        }

        private void merge(int u, int v, int[] par, int[] siz) {
            u = find(u, par);
            v = find(v, par);

            if (u == v) {
                return;
            }

            if (siz[u] > siz[v]) {
                int tmp = u;
                u = v;
                v = tmp;
            }

            par[u] = v;
            siz[v] += siz[u];
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String nextString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return nextString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}
