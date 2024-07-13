// Bucket sort with foating values (both positive and negative values)

import java.util.Collections;
import java.util.Scanner;
import java.util.ArrayList;

public class bucket_sort_floating_values {
    public static void main(String[] args) {
        int n, i;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();

        double[] arr = new double[n];
        for (i = 0; i < n; i++) {
            arr[i] = scan.nextDouble();
        }
//        double[] arr = new double[]{-0.897, 0.565, 0.656, -0.1234, 0, 0.3434};
        sort(arr);

        for (i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
    }

    public static void sort(double[] arr) {
        int i, n;
        n = arr.length;

        // split into negative and positive values
        ArrayList<Double> positive_val = new ArrayList<>();
        ArrayList<Double> negative_val = new ArrayList<>();
        for (i = 0; i < n; i++) {
            if (arr[i] < 0)
                negative_val.add(-1 * arr[i]);  // convert into positive value and add
            else
                positive_val.add(arr[i]);
        }
        // sort the values using bucket sort
        bucket_sort(positive_val);
        bucket_sort(negative_val);

        // merge the result
        int index = 0;
        int size = negative_val.size();
        for (i = size - 1; i >= 0; i--, index++)
            arr[index] = -1 * negative_val.get(i);

        size = positive_val.size();
        for (i = 0; i < size; i++, index++)
            arr[index] = positive_val.get(i);
    }

    public static void bucket_sort(ArrayList<Double> a) {
        int i, n, index;
        n = a.size();
        int k = n;

        // create k empty buckets
        ArrayList<Double>[] buckets = new ArrayList[k];
        for (i = 0; i < k; i++)
            buckets[i] = new ArrayList<>();

        // store the element in buckets
        for (i = 0; i < n; i++) {
            index = (int) (k * a.get(i));
            buckets[index].add(a.get(i));
        }

        // sort each buckets using inbuilt functions
        for (i = 0; i < k; i++)
            Collections.sort(buckets[i]);

        a.clear();
        for (i = 0; i < n; i++) {
            int size = buckets[i].size();
            for (int j = 0; j < size; j++) {
                a.add(buckets[i].get(j));
            }
        }
    }
}