class Solution {
public:
    int atMostSolver(vector<int>& nums,int goal){
        int left=0,right=0,oddCnt=0,atMost=0;
        while(right<nums.size()){
            if(goal<0)
                return 0;
            if(nums[right]%2==1)
                oddCnt++;
            while(oddCnt>goal){
                if(nums[left]%2==1)
                    oddCnt--;
                left++;
            }
            atMost+=right-left+1;
            right++;
        }
        return atMost;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostSolver(nums,k)-atMostSolver(nums,k-1);
    }
};