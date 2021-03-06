public class Solution121_2 {
    public int maxProfit(int[] prices) {
        int max = 0;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < min){
                min = prices[i];
            }else{
                max += prices[i]-min;
                min = prices[i];
            }
        }
        return max;
    }
}
