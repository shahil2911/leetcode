class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zerocnt=0,left=0,right=0,ans=0;
        int n=nums.size();
        while(right<n){
            if(nums[right]==0)
                zerocnt++;
            while(zerocnt>k){
                if(nums[left]==0)
                    zerocnt--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};