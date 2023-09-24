class Solution {
public:
    void solver(vector<vector<int>>& ans, vector<int>& temp, int idx, vector<int>& nums, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;  // Skip duplicates to avoid duplicate combinations.
            }
            
            if (nums[i] > target) {
                break;  // No need to check further if the number is too large.
            }

            temp.push_back(nums[i]);
            solver(ans, temp, i+1, nums, target - nums[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solver(ans, temp, 0, candidates, target);
        return ans;
    }
};
