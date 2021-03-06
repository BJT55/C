import java.util.HashSet;
import java.util.Set;

public class Solution128_2 {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums){
            set.add(num);
        }

        int longest = 0;
        for (int num : nums){
            if (!set.contains(num-1)){
                int currentNum = num;
                int currentLen = 1;

                while (set.contains(currentNum+1)){
                    currentLen++;
                    currentNum++;
                }
                longest = Math.max(longest,currentLen);
            }
        }
        return longest;
    }
}
