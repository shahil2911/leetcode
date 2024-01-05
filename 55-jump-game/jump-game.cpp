class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int maxIcanGo = nums[0] + 0;
        int target = nums.size() - 1;
        for(int i=1;i<nums.size() && maxIcanGo>=i;i++) {
            maxIcanGo = max(maxIcanGo, nums[i] + i);
            if(target<=maxIcanGo) {
                return true;
            }
        }
        return false;
    }
};