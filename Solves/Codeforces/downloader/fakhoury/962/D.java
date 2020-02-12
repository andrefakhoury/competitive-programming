import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.TreeMap;
import java.util.Scanner;
import java.util.TreeSet;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
     static class TaskD {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = new long[n];
            boolean[] deleted = new boolean[n];
             for (int i = 0; i < n; i++) {
                a[i] = in.nextLong();
                deleted[i] = false;
            }
             TreeMap<Long, TreeSet<Integer>> mp = new TreeMap<>();
            TreeSet<Long> allValues = new TreeSet<>();
             for (int i = 0; i < n; i++) {
                TreeSet<Integer> st;
                if (mp.containsKey(a[i])) st = mp.get(a[i]);
                else st = new TreeSet<>();
                 st.add(i);
                mp.put(a[i], st);
                 if (st.size() >= 2) allValues.add(a[i]);
            }
             while (!allValues.isEmpty()) {
                Long x = allValues.pollFirst();
                TreeSet<Integer> mpx = mp.get(x);
                 Integer pos1 = mpx.pollFirst();
                Integer pos2 = mpx.pollFirst();
                mp.put(x, mpx);
                 deleted[pos1] = true;
                a[pos2] = 2 * x;
                 TreeSet<Integer> cur;
                if (mp.containsKey(2 * x)) cur = mp.get(2L * x);
                else cur = new TreeSet<>();
                cur.add(pos2);
                mp.put(2L * x, cur);
                 if (mpx.size() >= 2) allValues.add(x);
                if (cur.size() >= 2) allValues.add(2L * x);
            }
             ArrayList<Long> ans = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (deleted[i]) continue;
                ans.add(a[i]);
            }
             out.println(ans.size());
            for (int i = 0; i < ans.size(); i++) out.print(ans.get(i) + " ");
            out.println();
        }
     }
}
 