import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class PairJava {

	public static void main(String[] args) {
		Pair<Integer, Integer> p = new Pair<>();

		p.first = 1;
		p.second = 10;

		p = new Pair(20, 30);

		System.out.println(p);
		
	}

	static class Pair<T, S> {
		public T first;
		public S second;

		@SuppressWarnings("unchecked")
		public Pair() {
			first = (T) new Object();
			second = (S) new Object();
		}

		@SuppressWarnings("unchecked")
		public Pair(T f, S s) {
			first = f;
			second = s;
		}

		@Override
		public String toString() {
			return first.toString() + " " + second.toString();
		}
	}
}
