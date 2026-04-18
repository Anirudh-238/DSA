#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                // If current left height is a new max, we can't trap water
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    // We can trap water because leftMax > current height
                    // and we know there is a wall at least as high on the right
                    totalWater += leftMax - height[left];
                }
                left++;
            } else {
                // Same logic for the right side
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    totalWater += rightMax - height[right];
                }
                right--;
            }
        }

        return totalWater;
    }
};