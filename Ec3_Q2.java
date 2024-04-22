// Given a chessboard, find the shortest distance (minimum number of steps) taken by a knight to
//  reach a given destination from a given source.
// For example,
// Input:
// N = 8 (8 × 8 board)
// Source = (7, 0)
// Destination = (0, 7)
// Output: Minimum number of steps required is 6

import java.util.*;

class Ec3_Q2
{
    static int shortestDistance(int n,int[] s,int[] d)
    {
        Queue<int []> q = new LinkedList<>();

        q.offer(new int[]{s[0],s[1],0});
        
        while(!q.isEmpty())
        {

        }
        return 0;
    }

    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        String input;
        int n;
        int[] src, dest;
        src = new int[2];
        dest = new int[2];
        System.out.print("Enter N :");
        n = scan.nextInt();
        System.out.print("Enter the source :");
        src[0] = scan.nextInt();
        src[1] = scan.nextInt();

        System.out.print("Enter the source :");
        dest[0] = scan.nextInt();
        dest[1] = scan.nextInt();


    }
}