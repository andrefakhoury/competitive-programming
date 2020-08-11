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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        ArrayList<Integer>[] edges;
        ArrayList<Integer>[] inved;
        ArrayList<Integer> order;
        ArrayList<Integer>[] sameColor;
        ArrayList<Integer>[] newEdge;
        int[] color;
        int[] hours;
        boolean[] vis;

        void dfs_order(int u) {
            vis[u] = true;
            for (Integer v : edges[u])
                if (!vis[v])
                    dfs_order(v);
            order.add(u);
        }

        void dfs_color(int u, int c) {
            color[u] = c;
            sameColor[c].add(u);
            for (Integer v : inved[u])
                if (color[v] == 0) {
                    dfs_color(v, c);
                }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int h = in.nextInt();

            hours = new int[n];
            edges = new ArrayList[n];
            inved = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                hours[i] = in.nextInt();
                edges[i] = new ArrayList<>();
                inved[i] = new ArrayList<>();
            }

            for (int i = 0; i < m; i++) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;

                if ((hours[u] + 1) % h == hours[v]) {
                    edges[u].add(v);
                    inved[v].add(u);
                }
                if ((hours[v] + 1) % h == hours[u]) {
                    edges[v].add(u);
                    inved[u].add(v);
                }
            }

            vis = new boolean[n];
            order = new ArrayList<>();
            for (int i = 0; i < n; i++)
                if (!vis[i])
                    dfs_order(i);
            Collections.reverse(order);
            color = new int[n];
            sameColor = new ArrayList[n + 1];
            for (int i = 0; i <= n; i++)
                sameColor[i] = new ArrayList<>();

            int currentColor = 0;
            for (Integer u : order)
                if (color[u] == 0)
                    dfs_color(u, ++currentColor);

            newEdge = new ArrayList[currentColor + 1];
            for (int i = 1; i <= currentColor; i++) {
                newEdge[i] = new ArrayList<>();
                for (Integer u : sameColor[i]) {
                    for (Integer v : edges[u])
                        if (color[v] != i) {
                            newEdge[i].add(color[v]);
                        }
                }
            }

            int answer = n + 1, idx = 0;
            for (int i = 1; i <= currentColor; i++)
                if (newEdge[i].isEmpty()) {
                    if (answer > sameColor[i].size()) {
                        answer = sameColor[i].size();
                        idx = i;
                    }
                }

            assert (idx != 0);

            out.println(answer);
            for (Integer u : sameColor[idx]) {
                out.print((u + 1) + " ");
            }
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

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}

