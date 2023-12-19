class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mpp(256, 0);  // Initialize the array with zeros instead of -1
        int left = 0, right = 0, res = 0;
        int maxf = 0;
        int n = s.size();
        
        while (right < n) {
            mpp[s[right]]++;
            maxf = max(maxf, mpp[s[right]]);
            
            // Check if the number of characters to be replaced exceeds k
            while ((right - left + 1) - maxf > k) {
                mpp[s[left]]--;
                left++;
            }
            
            // Update the result with the current substring length
            res = max(res, right - left + 1);  // Fix the indexing here
            
            right++;
        }
        
        return res;
    }
};