class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        long long sum = 0;  // Using a long long to prevent integer overflow
        
        stack<int> st;  // Stack to store indices of elements
        vector<int> left(n,-1);  // Store the nearest smaller element to the left
        vector<int> right(n,n);  // Store the nearest smaller element to the right
        
        // Calculate the nearest smaller element to the left for each element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }
            if(!st.empty()) left[i]=st.top();
            st.push(i);
        }
        
        while (!st.empty()) {
            st.pop();
        }
        
        // Calculate the nearest smaller element to the right for each element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                st.pop();
            }
            if(!st.empty()) right[i]=st.top();
            st.push(i);
        }
        
        for (int i = 0; i < n; i++) {
            // The number of subarrays ending at nums[i] where nums[i] is the minimum
            long long left_count = i - left[i];
            long long right_count = right[i] - i;
            
            // Add the contribution of nums[i] to the sum
            sum = (sum + (left_count * right_count * nums[i]) % MOD) % MOD;
        }
        
        return static_cast<int>(sum);
    }
};


// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         stack<int>s1,s2;
//         int n=arr.size();
//         vector<int>next_smaller(n),pre_smaller(n);
//         for(int i=0;i<n;i++){
//             next_smaller[i]=n-i-1;
//             pre_smaller[i]=i;
//         }
//         for(int i=0;i<n;i++){
//             while(!s1.empty() && arr[s1.top()]>arr[i]){
//                 next_smaller[s1.top()]=i-s1.top()-1;
//                 s1.pop();
//             }
//             s1.push(i);
//         }
//         for(int i=n-1;i>=0;i--){
//             while(!s2.empty() && arr[s2.top()]>=arr[i]){
//                 pre_smaller[s2.top()]=s2.top()-i-1;
//                 s2.pop();
//             }
//             s2.push(i);
//         }
//         long long ans = 0;
//         int mod = 1e9 + 7;
//         for (int i = 0; i < n; i++) {
//             ans += (static_cast<long long>(arr[i]) * (pre_smaller[i] + 1) * (next_smaller[i] + 1)) % mod;
//             ans %= mod;
//         }
//         return static_cast<int>(ans);
//     }
// };

