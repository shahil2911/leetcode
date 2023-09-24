class Solution {
public:
    void solver(vector<vector<int>>&ans,vector<int>&temp,int idx,vector<int>nums,int target){
        // if(target==0){
        //     ans.push_back(temp);
        //     return;
        // }

        if(idx==nums.size()){
            if(target==0)
                ans.push_back(temp);
            return;
        }
        if(nums[idx]<=target){
            temp.push_back(nums[idx]);
            solver(ans,temp,idx,nums,target-nums[idx]);
            temp.pop_back();
        }
        solver(ans,temp,idx+1,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> temp;
        solver(ans,temp,0,candidates,target);
        return ans;   
    }
};