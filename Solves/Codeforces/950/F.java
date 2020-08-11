import java.io.OutputStream;
import java.io.IOException;
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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        int n;
        int d;
        int b;
        int[] a;
        long[] sum;
        long[] current;

        int getCurrent(int last) {
            int answer = 0;

            long debt = 0;
            for (int i = 1; i <= last; i++) {
                long qttDebt = Math.min(current[i], debt);
                current[i] -= qttDebt;
                debt -= qttDebt;

                if (current[i] >= b) {
                    current[i + 1] += current[i] - b;
                } else {
                    int right = (int) Math.min(n, i + (long) d * i);
                    long qtt = sum[right] - sum[i] - debt;
                    long left = b - current[i];

                    if (left <= qtt) {
                        debt += left;
                    } else {
                        answer++;
                        current[i + 1] += current[i];
                    }
                }
            }

            return answer;
        }

        int f(long m) {
            Arrays.fill(sum, 0);
            Arrays.fill(current, 0);

            for (int i = 1; i <= n; i++) {
                long cur = Math.min(m - sum[i - 1], a[i]);
                current[i] = cur;
                sum[i] = sum[i - 1] + cur;
            }

            return getCurrent((n + 1) / 2);
        }

        int g(long m) {
            Arrays.fill(sum, 0);
            Arrays.fill(current, 0);

            for (int i = n, j = 1; j <= n; i--, j++) {
                long cur = Math.min(m - sum[j - 1], a[i]);
                current[j] = cur;
                sum[j] = sum[j - 1] + cur;
            }

            return getCurrent(n / 2);
        }

        int ans(long m) {
            if (m < 0 || m > (long) n * b) return Integer.MAX_VALUE;
            return Math.max(f(m), g((long) n * b - m));
        }

        int get(long m) {
            return g((long) n * b - m) - f(m);
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            d = in.nextInt();
            b = in.nextInt();

            a = new int[n + 1];
            for (int i = 1; i <= n; i++)
                a[i] = in.nextInt();

            sum = new long[n + 2];
            current = new long[n + 2];

            long lo = 0;
            long hi = (long) n * b;
            long mi;
            long answer = 0;
            while (lo <= hi) {
                mi = (lo + hi) / 2;
                if (get(mi) >= 0) {
                    hi = mi - 1;
                    answer = mi;
                } else {
                    lo = mi + 1;
                }
            }

            int best = Integer.MAX_VALUE;
            for (long i = answer - 5; i <= answer + 5; i++)
                best = Math.min(best, ans(i));

            out.println(best);
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
}

