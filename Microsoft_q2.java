import java.util.Scanner;

public class Microsoft_q2 {

    static void minString(int n) {
        int size = (int) (Math.log10(n) / Math.log10(2));
        int num, count = 0;
        char[] ch = new char[n];

        while (n > 0) {
            if(size > 25)
                size = 25;

            num = (int) Math.pow(2, size);
            n -= num;
            ch[count++] = (char) (97 + size);
            size = (int) (Math.log10(n) / Math.log10(2));
        }

        for (int i = 0; i < count; i++)
            System.out.print(ch[i] + " ");
    }

    public static void main(String[] args) {
        int n, i;
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter the no. of 'a' :");
        n = scan.nextInt();

        minString(n);
    }
}
