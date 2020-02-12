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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
     static class TaskC {
        long can(long x, long y) {
            String a = String.valueOf(x);
            String b = String.valueOf(y);
             if (x == y) return 0;
            if (a.length() < b.length()) return -1;
            if (a.length() == b.length()) return -1;
             // quero ver se posso deletar caracteres de a tal que vire b
            long ret = 0;
             int j = 0;
            for (int i = 0; i < a.length(); i++) {
                if (j == b.length()) ret++;
                else if (a.charAt(i) == b.charAt(j)) j++;
                else ret++;
            }
             if (j == b.length()) return ret;
            else return -1;
        }
         public void solve(int testNumber, Scanner in, PrintWriter out) {
            final long MAXI = 2000000000L;
             long x = in.nextLong();
             long ans = Long.MAX_VALUE;
            for (long i = 1; i * i <= x; i++) {
                long q = can(x, i * i);
                if (q != -1) ans = Math.min(ans, q);
            }
             if (ans == Long.MAX_VALUE) out.print(-1);
            else out.print(ans);
        }
     }
}
 