import java.util.*;

public class temp {
    public static void main(String args[]) {

//        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
//
//        // adding new arraylists to 'adj' to add neighbour nodes
//        for (int i = 0; i < 6; i++) {
//            adj.add(new ArrayList<>());
//        }
//
//        adj.get(5).add(2);
//        adj.get(5).add(0);
//        adj.get(4).add(0);
//        adj.get(4).add(1);
//        adj.get(3).add(1);
//        adj.get(2).add(3);
//        // adj.get(2).add(5);
//
//        boolean result = new Solution().isCyclic(6, adj);
//        System.out.println(result);

        ArrayList<Integer> arl = new ArrayList<>();
        ArrayList<Integer> arl2 = new ArrayList<>(List.of(1, 2, 3));

        arl.add(10);
        arl.add(20);
        arl.addAll(arl2);

        System.out.println(arl);

        for (Iterator<Integer> iterator = arl.iterator(); iterator.hasNext(); ) {
            Integer i = iterator.next();
            System.out.println(i);
        }
    }
}
