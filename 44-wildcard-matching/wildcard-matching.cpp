#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sIdx = 0, pIdx = 0;
        int lastSIdx = -1, starIdx = -1;
        int sLen = s.length(), pLen = p.length();

        while (sIdx < sLen) {
            // Case 1: Characters match or pattern is '?'
            if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            }
            // Case 2: Pattern is '*'
            else if (pIdx < pLen && p[pIdx] == '*') {
                starIdx = pIdx;
                lastSIdx = sIdx;
                pIdx++; // Try matching '*' with 0 characters first
            }
            // Case 3: No match, but we have a previous '*' to backtrack to
            else if (starIdx != -1) {
                pIdx = starIdx + 1; // Reset pattern to after the star
                lastSIdx++;         // Increment the range the star covers
                sIdx = lastSIdx;    // Reset string pointer
            }
            // Case 4: No match and no '*' to save us
            else {
                return false;
            }
        }

        // Check if remaining pattern characters are all '*'
        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == pLen;
    }
};