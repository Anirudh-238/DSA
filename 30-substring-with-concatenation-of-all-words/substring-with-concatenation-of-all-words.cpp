#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int n = s.length();
        int numWords = words.size();
        int wordLen = words[0].length();
        int totalLen = numWords * wordLen;

        unordered_map<string, int> counts;
        for (const string& w : words) counts[w]++;

        // Iterate through all possible starting offsets within one word length
        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;

            for (int j = i; j <= n - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);

                if (counts.count(word)) {
                    seen[word]++;
                    count++;

                    // If a word appears more times than in the input, shrink window
                    while (seen[word] > counts[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // Found a valid concatenation
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    // Word not in the list, reset the window
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        return result;
    }
};
