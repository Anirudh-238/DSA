#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Base index
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // Current ')' is a boundary breaker
                    st.push(i);
                } else {
                    // Valid pair found, calculate length using the new top
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};