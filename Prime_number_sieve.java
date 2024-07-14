// Prime number - optimal based on Sieve of Eratosthenes

import java.util.Arrays;
import java.util.Scanner;

public class Prime_number_sieve {
    static void soe(boolean[] arr) {
        Arrays.fill(arr, true);
        arr[0] = false;
        arr[1] = false;

        int n = arr.length;
        for (int i = 2; i * i < n; i++) {
            if (arr[i]) {
                for (int j = i * i; j < n; j += i) {
                    arr[j] = false;
                }
            }
        }
    }

    static void printPrime(int n) {
        boolean[] isPrime = new boolean[n+1];

        soe(isPrime);
        for (int i = 2; i <= n; i++)
            if (isPrime[i])
                System.out.print(i + " ");
    }

    public static void main(String[] args) {
        int n;
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter the n:");
        n = scan.nextInt();

        printPrime(n);
    }
}
