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
import java.util.Collections;
import java.util.ArrayList;
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
        CReadingBooksEasyVersion solver = new CReadingBooksEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class CReadingBooksEasyVersion {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();

            ArrayList<Integer> both = new ArrayList<>();
            ArrayList<Integer> a = new ArrayList<>();
            ArrayList<Integer> b = new ArrayList<>();

            a.add(0);
            b.add(0);
            both.add(0);

            for (int i = 0; i < n; i++) {
                int time = in.nextInt();
                boolean a_like = in.nextInt() == 1;
                boolean b_like = in.nextInt() == 1;

                if (a_like && b_like) {
                    both.add(time);
                } else if (a_like) {
                    a.add(time);
                } else if (b_like) {
                    b.add(time);
                }
            }

            Collections.sort(both);
            Collections.sort(a);
            Collections.sort(b);

            for (int i = 1; i < both.size(); i++) {
                both.set(i, both.get(i) + both.get(i - 1));
            }

            for (int i = 1; i < a.size(); i++) {
                a.set(i, a.get(i) + a.get(i - 1));
            }

            for (int i = 1; i < b.size(); i++) {
                b.set(i, b.get(i) + b.get(i - 1));
            }

            int answer = Integer.MAX_VALUE;
            for (int qt_both = 0; qt_both <= Math.min(k, both.size() - 1); qt_both++) {
                int qt_a = k - qt_both;
                int qt_b = k - qt_both;

                if (qt_a >= a.size() || qt_b >= b.size()) {
                    continue;
                }

                answer = Math.min(answer, both.get(qt_both) + a.get(qt_a) + b.get(qt_b));
            }

            out.println(answer < Integer.MAX_VALUE ? answer : -1);
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
