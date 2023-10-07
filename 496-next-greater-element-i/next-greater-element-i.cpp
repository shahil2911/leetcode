class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        vector<int> ans;
        
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int num = nums2[i];
            int next = -1;
            
            while (!ans.empty() && num > ans.back()) {
                ans.pop_back();
            }
            
            if (!ans.empty()) {
                next = ans.back();
            }
            
            nextGreater[num] = next;
            ans.push_back(num);
        }
        ans.clear();
        
        for (int num : nums1) {
            ans.push_back(nextGreater.count(num) ? nextGreater[num] : -1);
        }
        
        return ans;
    }
};
