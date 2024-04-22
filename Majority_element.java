// Majority element - Moore voting algorithm
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

import java.util.Scanner;

class Majority_element
{
    public static int majorityElement(int[] nums)
    {
        int count = 0, candidate = 0;

        for(int num : nums)
        {
            if(count == 0)
                candidate = num;

            if(num == candidate)
                count++;
            else 
                count--;
        }

        return candidate;
    }

    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int n, result;
        
        System.out.print("Enter the size :");
        n = scan.nextInt();
        int[] arr = new int[n];

        System.out.print("Enter the array :");
        for(int i=0;i<n;i++)
            arr[i] = scan.nextInt();

        result = majorityElement(arr);
        System.out.print("Majority Element :"+result);
    }
}