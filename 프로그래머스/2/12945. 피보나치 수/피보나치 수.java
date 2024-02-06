class Solution {
    int[] nums;
    public int solution(int n) {
        this.nums = new int[n+1];
        for(int i=0; i<=n; i++) {
            if(i == 0) {
                nums[i] = 0;
            } else if (i == 1) {
                nums[i] = 1;
            } else {
                nums[i] = (nums[i-2] + nums[i-1]) % 1234567 ;
            }
        }
        return nums[n];
    }
}