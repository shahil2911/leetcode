#include <string>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        int n = num.size();
        if (k >= n) {
            return "0"; // Remove all digits, so the result is 0.
        }

        std::string result = "";
        for (char ch : num) {
            while (k > 0 && !result.empty() && ch < result.back()) {
                result.pop_back();
                k--;
            }
            result.push_back(ch);
        }
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }

        // Handle the case when there are leading zeros.
        int i = 0;
        while (i < result.length() && result[i] == '0') {
            i++;
        }
        if (i == result.length()) {
            return "0";  // All digits were zeros.
        }

        return result.substr(i);
    }
};
