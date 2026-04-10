#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Take the first string as the initial prefix
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            // While the current string 'strs[i]' does not start with 'prefix'
            while (strs[i].find(prefix) != 0) {
                // Shorten the prefix by one character from the end
                prefix = prefix.substr(0, prefix.length() - 1);
                
                // If prefix becomes empty, there's no common prefix at all
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
};
