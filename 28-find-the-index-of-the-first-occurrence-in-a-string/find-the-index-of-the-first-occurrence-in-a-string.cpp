#include <string>

class Solution {
public:
    int strStr(string haystack, string needle) {
        int h_len = haystack.length();
        int n_len = needle.length();

        // Edge case: needle is longer than haystack
        if (n_len > h_len) return -1;

        // Iterate through haystack where a full needle could still fit
        for (int i = 0; i <= h_len - n_len; i++) {
            // Check if the substring starting at i matches needle
            if (haystack.substr(i, n_len) == needle) {
                return i;
            }
        }

        return -1;
    }
};