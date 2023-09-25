class Solution {
public:
    void solver(vector<vector<int>> &ans,vector<int> &temp,int idx,int k,int target){
        if(temp.size()==k){
            if(target==0){
               ans.push_back(temp); 
            }
            return;
        }
        for (int i = idx; i < 10; i++) {
            
            if (i > target) {
                break;  // No need to check further if the number is too large.
            }

            temp.push_back(i);
            solver(ans, temp, i+1, k, target - i);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solver(ans,temp,1,k,n);
        return ans;
        
    }
};