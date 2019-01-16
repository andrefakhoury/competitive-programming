import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Graph {
	int N; //vertex number
	LinkedList<Integer> edges[];
	boolean vis[];
	Integer dist[];

	Graph(int n) {
		this.N = n;
		this.edges = new LinkedList[n + 1];
		for (int i = 0; i <= n; i++)
			edges[i] = new LinkedList();
	}

	void addEdge(int u, int v) {
		edges[u].add(v);
	}

	int BFS(int s, int d) { //start and destiny
		dist = new Integer[N + 1];
		for (int i = 0; i <= N; i++) dist[i] = -1;

		LinkedList<Integer> q = new LinkedList<Integer>();

		dist[s] = 0;
		q.add(s);

		while(q.size() > 0) {
			int u = q.poll();

			Iterator<Integer> i = edges[u].listIterator();
			while(i.hasNext()) {
				int v = i.next();
				if (dist[v] == -1) {
					dist[v] = dist[u] + 1;
					q.add(v);
				}
			}
		}

		return dist[d];
	}

	public static void main(String []x) {
		Graph g = new Graph(5);
		g.addEdge(1, 2);
		g.addEdge(2, 3);
		g.addEdge(3, 4);
		g.addEdge(4, 5);

		System.out.println(g.BFS(1, 4));
	}
}