class Solution {
public:
    bool isPowerOfTwo(int n) {
        // int mask=1;
        // while(mask<n){
        //     mask=mask<<1;
        // }
        // return mask&n;
        if (n <= 0) {
        return false;  // Negative numbers and zero cannot be powers of two.
        }
        return (n & (n - 1)) == 0;
    }
};