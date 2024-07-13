class temp
{
    public static void main(String []args)
    {
        int []arr = new int[]{1,2,3,4,5};

        modify(arr);

        for(int i=0;i<5;i++)
            System.out.print(arr[i]+" ");
    }

    static void modify(int []arr)
    {
        arr[3] = 5;
    }
}