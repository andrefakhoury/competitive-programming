import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;
 /**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
     static class TaskB {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int a = in.nextInt();
            int b = in.nextInt();
            String s = in.next();
             int ans = 0;
            ArrayList<Integer> lst = new ArrayList<>();
            for (int i = 0, c = 0; i < n; i++) {
                if (s.charAt(i) == '*') {
                    if (c > 0) lst.add(c);
                    c = 0;
                } else {
                    c++;
                }
                 if (i == n - 1 && c > 0) lst.add(c);
            }
             Collections.sort(lst);
            Collections.reverse(lst);
             for (int i = 0; i < lst.size(); i++) {
                int x = lst.get(i);
                if (a < b) {
                    int c = a;
                    a = b;
                    b = c;
                }
                 if (a > 0) {
                    int qtt = Math.min((x + 1) / 2, a);
                    a -= qtt;
                    ans += qtt;
                     if (b > 0) {
                        int cc = Math.min(x - qtt, b);
                        b -= cc;
                        ans += cc;
                    }
                }
            }
             out.print(ans);
        }
     }
}
 