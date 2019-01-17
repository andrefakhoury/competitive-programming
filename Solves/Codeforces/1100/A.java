import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.*;
import java.lang.*;
import java.io.*;

public class A {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

		Integer n = in.nextInt();
		Integer k = in.nextInt();

		Integer[] tab = new Integer[n+1];
		Integer sum = 0;

		for (int i = 1; i <= n; i++) {
			tab[i] = in.nextInt();
			sum += tab[i];
		}

		Integer ans = 0;
		for (int b = 1; b <= n; b++) {
			Integer cur = sum;
			for (int i = -100; i <= 100; i++) {
				int t = b + i * k;

				if (t < 1 || t > n) continue;
				cur -= tab[t];
			}

			ans = Math.max(ans, Math.abs(cur));
		}

		System.out.println(ans);
	}
}