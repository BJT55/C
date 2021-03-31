public class Solution42 {
    public int maxSubArray(int[] nums){
        int res = nums[0];
        for (int i = 1; i < nums.length; ++i){
            nums[i] += Math.max(nums[i-1]+nums[i], nums[i]);
            res = Math.max(res, nums[i]);
        }
        return res;
    }
}
