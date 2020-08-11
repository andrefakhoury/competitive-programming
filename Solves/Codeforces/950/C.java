import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            String s = in.nextString();
            int n = s.length();

            List<List> sequences = new ArrayList<>();
            List<Integer>[] positions = new ArrayList[2];
            positions[0] = new ArrayList<Integer>();
            positions[1] = new ArrayList<Integer>();

            for (int i = 0; i < n; i++) {
                int curr = s.charAt(i) == '1' ? 1 : 0;
                if (curr == 0) {
                    if (positions[1].size() == 0) {
                        sequences.add(new ArrayList());
                        sequences.get(sequences.size() - 1).add(i + 1);
                        positions[0].add(sequences.size() - 1);
                    } else {
                        int last = positions[1].get(positions[1].size() - 1);
                        positions[1].remove(positions[1].size() - 1);
                        positions[0].add(last);
                        sequences.get(last).add(i + 1);
                    }
                } else {
                    if (positions[0].size() == 0) {
                        out.print(-1);
                        return;
                    }

                    int last = positions[0].get(positions[0].size() - 1);
                    positions[0].remove(positions[0].size() - 1);
                    positions[1].add(last);
                    sequences.get(last).add(i + 1);
                }

            }

            if (positions[1].size() >= 1) {
                out.print(-1);
            } else {
                out.println(sequences.size());
                for (List<Integer> current : sequences) {
                    out.print(current.size(), ' ');
                    for (Integer i : current)
                        out.print(i, ' ');
                    out.println();
                }
            }
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
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
}

