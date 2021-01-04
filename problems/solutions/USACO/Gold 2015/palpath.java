import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("palpath.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("palpath.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Problem2PalindromicPaths solver = new Problem2PalindromicPaths();
        solver.solve(1, in, out);
        out.close();
    }

    static class Problem2PalindromicPaths {
        final int MOD = (int) 1e9 + 7;
        int[][][] memo;
        String[] s;

        int solve(int count, int row1, int col1, int row2, int col2) {
            if (row1 > row2 || col1 > col2) return 0;
            if (memo[count][row1][row2] != -1)
                return memo[count][row1][row2];
            if (s[row1].charAt(col1) != s[row2].charAt(col2)) return 0;
            if (col1 == col2 && row1 + 1 >= row2) return 1;
            if (row1 == row2 && col1 + 1 >= col2) return 1;
            int answer = 0;
            answer += solve(count + 1, row1 + 1, col1, row2 - 1, col2);
            answer %= MOD;
            answer += solve(count + 1, row1 + 1, col1, row2, col2 - 1);
            answer %= MOD;
            answer += solve(count + 1, row1, col1 + 1, row2 - 1, col2);
            answer %= MOD;
            answer += solve(count + 1, row1, col1 + 1, row2, col2 - 1);
            answer %= MOD;
            return memo[count][row1][row2] = answer;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            s = new String[n];
            for (int i = 0; i < n; i++) s[i] = in.nextString();
            memo = new int[n][n][n]; // round, i1, i2. com isso, podemos calcular j1 e j2

            for (int[][] x : memo) for (int[] y : x) Arrays.fill(y, -1);
            out.println(solve(0, 0, 0, n - 1, n - 1));
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

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

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
}

