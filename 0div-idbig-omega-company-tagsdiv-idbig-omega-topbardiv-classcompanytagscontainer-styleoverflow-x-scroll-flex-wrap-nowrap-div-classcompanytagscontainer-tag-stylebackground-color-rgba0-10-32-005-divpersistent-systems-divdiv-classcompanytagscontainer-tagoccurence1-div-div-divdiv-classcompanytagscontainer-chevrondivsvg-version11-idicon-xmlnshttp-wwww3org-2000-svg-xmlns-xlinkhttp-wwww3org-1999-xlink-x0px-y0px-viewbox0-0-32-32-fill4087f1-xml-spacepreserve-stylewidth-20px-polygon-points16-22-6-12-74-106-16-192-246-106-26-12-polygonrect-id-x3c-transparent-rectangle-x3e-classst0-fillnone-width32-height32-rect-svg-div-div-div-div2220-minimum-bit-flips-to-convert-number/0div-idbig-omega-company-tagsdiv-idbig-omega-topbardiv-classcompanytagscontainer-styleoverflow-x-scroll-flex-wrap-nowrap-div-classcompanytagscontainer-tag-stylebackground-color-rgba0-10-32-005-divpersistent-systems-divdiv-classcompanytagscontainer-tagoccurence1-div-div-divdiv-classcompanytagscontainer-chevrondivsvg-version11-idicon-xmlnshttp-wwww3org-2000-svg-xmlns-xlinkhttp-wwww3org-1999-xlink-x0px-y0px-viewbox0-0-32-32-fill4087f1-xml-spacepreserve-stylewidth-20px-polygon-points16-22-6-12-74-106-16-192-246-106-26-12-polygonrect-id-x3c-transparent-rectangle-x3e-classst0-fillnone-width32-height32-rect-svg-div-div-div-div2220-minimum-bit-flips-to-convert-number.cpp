class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0, mask = 1;
        while (start != goal) {
            if ((mask & start) != (mask & goal)) {
                // If the current bit in start is different from the current bit in goal,
                // flip the bit in start.
                start ^= mask;
                cnt++;
            }
            mask <<= 1;
        }
        return cnt;
    }
};
