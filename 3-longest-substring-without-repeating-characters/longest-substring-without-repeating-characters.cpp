// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         vector<int> mpp(256,-1);//string contains 256 characters
//         int left=0, right=0,len=0;
//         int n=s.size();     
//         while(right<n){
//             if(mpp[s[right]]!=-1)
//                 left=max(left,mpp[s[right]]+1);
//             mpp[s[right]]=right;
//             len=max(len,right-left+1);
//             right++;
//         }
//         return len;
//     }
// };


class Solution {
public:
    int solve(string str) {

        if(str.size()==0)
            return 0;
        int maxans = INT_MIN;
        unordered_set < int > set;
        int l = 0;
        for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
        {
            if (set.find(str[r]) != set.end()) //if duplicate element is found
            {
                while (l < r && set.find(str[r]) != set.end()) {
                    set.erase(str[l]);
                    l++;
                }
            }
            set.insert(str[r]);
            maxans = max(maxans, r - l + 1);
        }
        return maxans;
    }
    int lengthOfLongestSubstring(string s) {
        return solve(s);
    }
};