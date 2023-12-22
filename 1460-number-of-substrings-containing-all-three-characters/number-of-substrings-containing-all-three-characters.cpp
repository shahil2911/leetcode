// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n=s.size(), cnt=0;

//         for(int i=0;i<n;i++){
//             unordered_map<char,int> mp;
//             for(int j=i;j<n;j++){
//                 mp[s[j]]++;
//                 if(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
//                     cnt+=n-j;
//                     break;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0,right=0, cnt=0, n=s.size();
        unordered_map<char,int> mp;
        while(right<n){
            mp[s[right]]++;
            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
                cnt+=n-right;
                mp[s[left]]--;
                left++;
            }
            right++;
        }
        return cnt;
    }
};