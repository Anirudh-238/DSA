#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // Base case: if the current string length is 2*n, we found a valid combination
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Decision 1: Can we add an opening parenthesis?
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }

        // Decision 2: Can we add a closing parenthesis?
        // Only if there are more open brackets than closed ones
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};
