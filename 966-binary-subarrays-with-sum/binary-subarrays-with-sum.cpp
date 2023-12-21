// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         unordered_map<int,int>mp;
//         mp[0]=1;
//         int pS=0, count=0;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             pS+=nums[i];
//             if(mp[pS-goal])
//                 count+=mp[pS-goal];
//             mp[pS]++;
//         }
//         return count;
//     }
// };

class Solution {
public:
    int solverAtMost(vector<int>& nums, int goal) {
        int left = 0, right = 0;
        int n = nums.size(), sum = 0, atMost = 0;
        
        if (goal < 0)
            return 0;

        while (right < n) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            atMost += right - left + 1;
            right++;
        }
        return atMost;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solverAtMost(nums, goal) - solverAtMost(nums, goal - 1);
    }
};