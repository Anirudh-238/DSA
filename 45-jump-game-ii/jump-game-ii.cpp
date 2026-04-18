#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        // We don't need to jump from the last element
        for (int i = 0; i < n - 1; i++) {
            // Update the farthest point we can reach from the current window
            farthest = max(farthest, i + nums[i]);

            // If we've reached the end of the range for the current jump
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                
                // If we can already reach the end, break early
                if (currentEnd >= n - 1) break;
            }
        }

        return jumps;
    }
};