import java.util.*;

class Graph
{
    int[][] edges;
    int size;

    Graph(int n)
    {
        edges = new int[n][n];
        size = n;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                edges[i][j] = Integer.MAX_VALUE;
    }

    void addEdge(int src, int dest, int cost)
    {
        if(src >= 0 && src < size && dest >= 0 && dest < size)
            edges[src][dest] = cost;
            edges[dest][src] = cost;
    }

    int maximumPath(int start, int k)
    {
        Queue<Node> q = new LinkedList<>();

        Set<Integer> v = new HashSet<>();
        v.add(start);
        q.add(new Node(start,0,v));
    
        int maxCost = Integer.MIN_VALUE;
        Node n;
        int cur, cost;
        Set<Integer> s;

        while(!q.isEmpty())
        {
            n = q.poll();

            cur = n.current;
            cost = n.cost;
            v = n.visited;

            if(cost > k)  
                maxCost = Math.max(cost,maxCost);

            for(int dest=0; dest<size; dest++)
            {
                int newCost = edges[cur][dest];
                if(newCost != Integer.MAX_VALUE && (!v.contains(dest)))
                {
                    s = new HashSet<>(v);
                    s.add(dest);
                    q.add(new Node(dest,cost+newCost,s));
                }
            }
        }

        return maxCost;
    }
}

class Node
{
    int current, cost;
    Set<Integer> visited;

    Node(int cur, int cost, Set<Integer> v)
    {
        this.current = cur;
        this.cost = cost;
        this.visited = v;
    }
}

class MaximumCostPath
{
    public static void main(String[] args)
    {
        // Scanner scan = new Scanner(System.in);
        // System.out.print("Enter the no. of edges :");

        int n, src, dest, cost;
        n = 8;
        cost = 50;
        src = 0;

        Graph g = new Graph(n);
        g.addEdge(0,1,5);
        g.addEdge(0,6,11);
        g.addEdge(1,0,5);
        g.addEdge(1,7,6);
        g.addEdge(1,6,3);
        g.addEdge(1,5,5);
        g.addEdge(1,2,7);
        g.addEdge(2,1,7);
        g.addEdge(2,5,-1);
        g.addEdge(2,3,-8);
        g.addEdge(3,2,-8);
        g.addEdge(3,5,9);
        g.addEdge(3,4,10);
        g.addEdge(4,3,10);
        g.addEdge(4,5,1);
        g.addEdge(5,6,2);
        g.addEdge(5,1,5);
        g.addEdge(5,2,-1);
        g.addEdge(5,3,9);
        g.addEdge(5,4,1);
        g.addEdge(6,7,9);
        g.addEdge(6,0,11);
        g.addEdge(6,1,3);
        g.addEdge(6,5,2);
        g.addEdge(7,1,6);
        g.addEdge(7,6,9);

        int result = g.maximumPath(src,cost);
        if(result != Integer.MIN_VALUE)
            System.out.println(result);
        else
            System.out.print("All paths have cost < "+cost);
    }
}