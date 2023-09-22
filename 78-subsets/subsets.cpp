class Solution {
public:
    void solver(vector<vector<int>>&ans,vector<int>&temp,int idx,vector<int>& nums){
        if(idx==nums.size()){
            ans.push_back(temp);
            return;
        }
        solver(ans,temp,idx+1,nums);
        temp.push_back(nums[idx]);
        solver(ans,temp,idx+1,nums);
        temp.pop_back();
        return;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solver(ans,temp,0,nums);
        return ans;
    }
};