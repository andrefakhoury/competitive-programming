import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class A {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

		int n = in.nextInt();
		int ans = 0;

		for (int i = 0; i < n; i++) {
			String s = in.next();

			if (s.equals("Tetrahedron")) ans += 4;
			if (s.equals("Cube")) ans += 6;
			if (s.equals("Octahedron")) ans += 8;
			if (s.equals("Dodecahedron")) ans += 12;
			if (s.equals("Icosahedron")) ans += 20;
		}

		System.out.println(ans);
	}
}