import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
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
        TaskXXXXX solver = new TaskXXXXX();
        solver.solve(1, in, out);
        out.close();
    }
     static class TaskXXXXX {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
             long sum = 0;
             int a[] = new int[n];
             for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                sum += a[i];
            }
             long cur = 0;
            for (int i = 0; i < n; i++) {
                cur += a[i];
                if (cur * 2 >= sum) {
                    out.print(i + 1);
                    return;
                }
            }
        }
     }
}
 