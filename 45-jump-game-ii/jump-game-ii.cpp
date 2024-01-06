class Solution {
public:
    int jump(vector<int>& nums) {
        int reach=0, count=0, last=0;
        // reach: maximum reachable index from current position
        // count: number of jumps made so far
        // last: rightmost index that has been reached so far  
        for(int i=0;i<nums.size()-1;i++){ 
            reach = max(reach, i+nums[i]);
            if(i==last){
                last = reach;
                count++;
            }
        }
        return count;
    }
};