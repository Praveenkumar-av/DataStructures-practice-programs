import java.util.*;

class Solution {
    public static boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        int[] indegree = new int[V];
        Arrays.fill(indegree, 0);

        // find the indegree of each node
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < V; i++) {
            for (int conn : adj.get(i))
                indegree[conn]++;
        }

        // add all nodes with indegree 0 to queue
        for (int i = 0; i < V; i++)
            if (indegree[i] == 0)
                q.offer(i);

        int[] result = new int[V];
        int i = 0;
        int count = 0;
        while (!q.isEmpty()) {
            int vertex = q.poll();
            count++;
            System.out.println(vertex);
            result[i++] = vertex;
            for (int conn : adj.get(vertex)) {
                indegree[conn]--;
                if (indegree[conn] == 0)
                    q.offer(conn);
            }
        }
        // printing topological ordering of nodes
        for (i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
        if (count == V)
            return false;
        return true;
    }
}

class course_schedule_2 {
    public static void main(String args[]) {

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        // adding new arraylists to 'adj' to add neighbour nodes
        for (int i = 0; i < 6; i++) {
            adj.add(new ArrayList<>());
        }

        adj.get(5).add(2);
        adj.get(5).add(0);
        adj.get(4).add(0);
        adj.get(4).add(1);
        adj.get(3).add(1);
        adj.get(2).add(3);
        // adj.get(2).add(5);

        boolean result = new Solution().isCyclic(6, adj);
        System.out.println(result);
    }
}
