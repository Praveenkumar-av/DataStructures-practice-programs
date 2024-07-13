import java.util.*;
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int i, left, right, n, sum;
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        n = nums.length;
        for(i=0;i<n-2;i++)
        {
            if(i!=0 && nums[i] == nums[i-1])
                continue;

            left = i+1;
            right = n-1;
            while(left < right) 
            {
                sum = nums[i] + nums[left] + nums[right];
                if(sum == 0)
                {
                    result.add(Arrays.asList(nums[i],nums[left],nums[right]));

                    while(left < right && nums[left] == nums[left+1])
                        left++;
                    
                    while(left < right && nums[right] == nums[right-1])
                        right--;

                    left++;
                    right--;
                }
                else if(sum < 0)
                    left++;
                else 
                    right--;
            }
        }
        return result;
    }
}