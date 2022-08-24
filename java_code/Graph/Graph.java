package Graph;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class Graph
{
    private int num_vtx;
    private LinkedList<Integer>[] adjList;
    private boolean[] visited;

    Graph(int num_vtx)
    {
        this.num_vtx = num_vtx;
        adjList = new LinkedList[num_vtx];
        for(int i=0; i<num_vtx; i++){
            adjList[i] = new LinkedList<Integer>();
        }
        visited = new boolean[num_vtx];
    }

    private void addEdge(int v, int w)
    {
        adjList[v].add(w);
    }

    private void do_bfs(int source)
    {
        Queue<Integer> queue = new LinkedList<Integer> ();
        visited[source] = true;
        queue.add(source);

        while(queue.size() != 0){
            int v = queue.poll();
            System.out.println(v + " ");

            Iterator<Integer> iter = adjList[v].listIterator();
            while(iter.hasNext()){
                int w = iter.next();
                if(!visited[w])
                {
                    visited[w] = true;
                    queue.add(w);
                }
            }
        }
    }

    private void do_dfs(int source)
    {
        visited[source] = true;
        System.out.println(source + " ");

        Iterator<Integer> iter = adjList[source].listIterator();
        while(iter.hasNext()){
            int neighbor = iter.next();
            if(!visited[neighbor])
                do_dfs(neighbor);
        }
    }

    public static void main(String[] args)
    {
        Graph g = new Graph(4);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        // g.do_bfs(2);
        g.do_dfs(2);

    }
}
