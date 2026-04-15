#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string res = "1";
        
        // Perform the transformation n-1 times
        for (int i = 2; i <= n; i++) {
            string current = "";
            int len = res.length();
            
            for (int j = 0; j < len; j++) {
                int count = 1;
                // Count consecutive identical characters
                while (j + 1 < len && res[j] == res[j + 1]) {
                    count++;
                    j++;
                }
                // Append "Count" + "Character"
                current += to_string(count) + res[j];
            }
            res = current;
        }
        
        return res;
    }
};