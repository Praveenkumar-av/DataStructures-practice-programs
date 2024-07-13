import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class TreeNode{
    int val;
    List<TreeNode> neighbors;
    boolean visited;

    TreeNode(int val) {
        this.val = val;
        this.neighbors = new ArrayList<>();
        this.visited = false;
    }
}

public class TreeColour{

    // DFS to assign colors and calculate distances
    public static void dfs(TreeNode node, int depth, int[] distances, int[] colorCounts) {
        node.visited = true;
        distances[depth % 2]++;
        for (TreeNode neighbor : node.neighbors) {
            if (!neighbor.visited) {
                dfs(neighbor, depth + 1, distances, colorCounts);
            }
        }
    }

    // Function to find good coloring
    public static void findGoodColoring(TreeNode root, int n) {
        int[] distances = new int[2]; // distances between nodes of the same color
        int[] colorCounts = new int[2]; // count of red and blue nodes

        dfs(root, 0, distances, colorCounts);

        // Output coloring
        System.out.println("Coloring the tree:");
        if (distances[0] == distances[1]) {
            // If distances are equal, assign arbitrary colors
            assignColors(root,true);
        } else {
            // Assign colors based on the lesser distance
            boolean red = distances[0] < distances[1];
            assignColors(root, red);
        }
    }

    // Assign colors to nodes
    public static void assignColors(TreeNode node, boolean red) {
        if (red) {
            System.out.println("Node " + node.val + " is red");
        } else {
            System.out.println("Node " + node.val + " is blue");
        }
        node.visited = false;
        for (TreeNode neighbor : node.neighbors) {
            if (neighbor.visited) {
                assignColors(neighbor,!red);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of nodes: ");
        int n = scanner.nextInt();

        TreeNode[] nodes = new TreeNode[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new TreeNode(i + 1);
        }

        System.out.println("Enter the edges:");
        for (int i = 0; i < n - 1; i++) {
            int node1 = scanner.nextInt();
            int node2 = scanner.nextInt();
            nodes[node1 - 1].neighbors.add(nodes[node2 - 1]);
            nodes[node2 - 1].neighbors.add(nodes[node1 - 1]);
        }

        findGoodColoring(nodes[0], n);
    }
